/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:36:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 18:34:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

char	**split_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (ft_split((*env + 5), ':'));
}

void	start_pipex(t_pipex *p, int ac, char **av, char **env)
{
	p->infile = open(av[1], O_RDONLY);
	if (p->infile < 0)
		print_merr(p, 2);
	p->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 00644);
	if (p->outfile < 0)
		print_merr(p, 2);
	if (pipe(p->pid_fd) < 0)
		print_merr(p, 24);
	p->paths = split_paths(env);
	p->prog = NULL;
	p->cmds = NULL;
}

void	clear_pipex(t_pipex *p)
{
	int	i;

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

int	cat_path(t_pipex *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((p->paths)[i])
	{
		tmp = ft_strjoin((p->paths)[i], "/");
		p->prog = ft_strjoin(tmp, p->cmds[0]);
		if (tmp)
			free(tmp);
		if (access(p->prog, F_OK) == 0)
		{
			if (access(p->prog, X_OK) < 0)
				err_msg_full(p, 1);
			return (1);
		}
		if (p->prog)
			free(p->prog);
		i++;
	}
	p->prog = NULL;
	return (0);
}

void	setup_path_cmd(t_pipex *p, char *cmd)
{
	handle_cmd(cmd);
	p->cmds = ft_split(cmd, NOPRINT);
	remove_symbols(p->cmds);
	if (cat_path(p))
		return ;
	err_msg_full(p, 127);
}
