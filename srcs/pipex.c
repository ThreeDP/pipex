/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/28 19:00:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include "libft/minilibft.h"

char    **split_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (ft_split((*env + 5), ':'));
}

void    start_pipex(t_pipex *p, int ac, char **av, char **env)
{
	p->infile = open(av[1], O_RDONLY);
	if (p->infile < 0)
	{
		if (p)
			free(p);
		merr(2);
	}
	p->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 00644);
	if (p->outfile < 0)
	{
		if (p)
			free(p);
		merr(2);
	}
	if (pipe(p->pid_fd) < 0)
	{
		if (p)
			free(p);
		merr(24);
	}
	p->paths = split_paths(env);
	p->prog = NULL;
	p->cmds = NULL;
}

void	setup_path_cmd(t_pipex *p, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	handle_cmd(cmd);
	p->cmds = ft_split(cmd, 7);
	while ((p->paths)[i])
	{
		tmp = ft_strjoin((p->paths)[i], "/");
		p->prog = ft_strjoin(tmp, p->cmds[0]);
		if (tmp)
			free(tmp);
		if (access(p->prog, F_OK) == 0)
			return ;
		if (p->prog)
			free(p->prog);
		i++;
	}
	p->prog = NULL;
	i = 0;
	while((p->cmds)[i])
		free((p->cmds)[i++]);
	clear_pipex(p);
	perror("ERROR");
	exit(2);
}

int	first_pid(t_pipex *p, char **env, char *cmd)
{
	int i;

	i = 0;
	if (p->pid1 < 0)
	{
		clear_pipex(p);
		merr(127);
	}
	if (p->pid1 == 0)
	{
		setup_path_cmd(p, cmd);
		dup2(p->infile, STDIN_FILENO);
		dup2(p->pid_fd[1], STDOUT_FILENO);
		close(p->pid_fd[1]);
		close(p->pid_fd[0]);
		if (execve(p->prog, p->cmds, env) < 0)
		{
			i = 0;
			while((p->cmds)[i])
				free((p->cmds)[i++]);
			clear_pipex(p);
			perror("ERROR");
			exit(24);
		}
	}
	return (0);
}

int	second_pid(t_pipex *p, char **env, char *cmd)
{
	int i;

	i = 0;
	if (0 > p->pid2)
	{
		clear_pipex(p);
		merr(127);
	}
	if (p->pid2 == 0)
	{
		setup_path_cmd(p, cmd);
		dup2(p->pid_fd[0], STDIN_FILENO);
		dup2(p->outfile, STDOUT_FILENO);
		close(p->pid_fd[0]);
		close(p->pid_fd[1]);
		if (execve(p->prog, p->cmds, env) < 0)
		{
			i = 0;
			while((p->cmds)[i])
				free((p->cmds)[i++]);
			clear_pipex(p);
			perror("ERROR");
			exit(24);
		}
	}
	return (0);
}

void	clear_pipex(t_pipex *p)
{
	int i;

	if (p->prog)
		free(p->prog);
	i = 0;
	while ((p->paths)[i])
		free((p->paths)[i++]);
	if (p->paths)
		free(p->paths);
	if (p->cmds)
		free(p->cmds);
	if (p)
		free(p);
}

int main(int argc, char **argv)
{
	t_pipex     *p;
	int			status;
	int			d;
	extern char **environ;

	if (argc != 5)
		return (message(ERR_AGRS));
	p = (t_pipex *) malloc(sizeof(t_pipex));
	start_pipex(p, argc, argv, environ);
	p->pid1 = fork();
	first_pid(p, environ, argv[2]);
	p->pid2 = fork();
	second_pid(p, environ, argv[3]);	
	close(p->pid_fd[0]);
	close(p->pid_fd[1]);
	waitpid(p->pid1, &status, 0);
	waitpid(p->pid2, &status, 0);
	clear_pipex(p);
	return (WEXITSTATUS(status));
}
