/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:37:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/15 17:33:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

void	close_fds(t_pipex *p)
{
	close(p->pid_fd[0]);
	close(p->pid_fd[1]);
	close(p->infile);
	close(p->outfile);
}

void	run_execve(t_pipex *p, char **env)
{
	int	i;

	i = 0;
	if (execve(p->prog, p->cmds, env) < 0)
		err_msg_full(p, 24);
	while ((p->cmds)[i])
		free((p->cmds)[i++]);
}

int	first_pid(t_pipex *p, char **env, char *cmd)
{
	int	i;

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
		close_fds(p);
		run_execve(p, env);
	}
	return (0);
}

int	second_pid(t_pipex *p, char **env, char *cmd)
{
	int	i;

	i = 0;
	if (0 > p->pid2)
	{
		clear_pipex(p);
		merr(127);
	}
	if (p->pid2 == 0)
	{
		setup_path_cmd(p, cmd);
		i = 0;
		dup2(p->pid_fd[0], STDIN_FILENO);
		dup2(p->outfile, STDOUT_FILENO);
		close_fds(p);
		run_execve(p, env);
	}
	return (0);
}
