/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:03 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/29 15:20:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

char    **split_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (ft_split((*env + 5), ':'));
}

void    start_pipex(t_pipex **p, int ac, char **av, char **env)
{
	(*p)->infile = open(av[1], O_RDONLY);
	if ((*p)->infile < 0)
		merr(ERR_IFILE);
	(*p)->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 00644);
	if ((*p)->outfile < 0)
		merr(ERR_OFILE);
	if (pipe((*p)->pid_fd) < 0)
		merr(ERR_PIPE);
	(*p)->paths = split_paths(env);
	(*p)->prog = NULL;
	(*p)->cmds = NULL;
}

void	setup_path_cmd(t_pipex **p, char *cmd)
{
	char	*tmp;

	(*p)->cmds = ft_split(cmd, ' ');
	while (*(*p)->paths)
	{
		tmp = ft_strjoin(*(*p)->paths, "/");
		(*p)->prog = ft_strjoin(tmp, (*p)->cmds[0]);
		if (tmp)
			free(tmp);
		if (access((*p)->prog, F_OK) == 0)
			return ;
		free((*p)->prog);
		(*p)->paths++;
	}
	(*p)->prog = NULL;
}

int	first_pid(t_pipex **p, char **env, char *cmd)
{
	if (0 > (*p)->pid1)
		return (2);
	if ((*p)->pid1 == 0)
	{
		setup_path_cmd(p, cmd);
		dup2((*p)->pid_fd[1], STDOUT_FILENO);
		close((*p)->pid_fd[1]);
		close((*p)->pid_fd[0]);
		execve((*p)->prog, (*p)->cmds, env);
	}
	return (0);
}

int	second_pid(t_pipex **p, char **env, char *cmd)
{
	if (0 > (*p)->pid2)
		return (2);
	if ((*p)->pid2 == 0)
	{
		setup_path_cmd(p, cmd);
		dup2((*p)->pid_fd[0], STDIN_FILENO);
		dup2((*p)->pid_fd[1], STDOUT_FILENO);
		close((*p)->pid_fd[0]);
		close((*p)->pid_fd[1]);
		dup2((*p)->outfile, STDOUT_FILENO);
		execlp("wc", "wc -l", NULL);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_pipex     *p;
	extern char **environ;

	if (argc != 5)
		return (message(ERR_AGRS));
	p = (t_pipex *) malloc(sizeof(t_pipex));
	start_pipex(&p, argc, argv, environ);
	p->pid1 = fork();;
	first_pid(&p, environ, argv[2]);
	p->pid2 = fork();
	second_pid(&p, environ, argv[3]);	
	close(p->pid_fd[0]);
	close(p->pid_fd[1]);
	waitpid(p->pid1, NULL, 0);
	waitpid(p->pid2, NULL, 0);
	return 0;
}
