/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:36:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/03 01:28:05 by dapaulin         ###   ########.fr       */
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

void	remove_symbols(char **cmds)
{
	int		i;
	int		j;
	char	*sq;

	i = 0;
	sq = NULL;
	while (*cmds)
	{
		while ((*cmds)[i])
		{
			if (((*cmds)[i] == 39 || (*cmds)[i] == 34) && (*cmds)[i - 1] != 92)
				(*cmds)[i] = 7;
			i++;
		}
		i = 0;
		j = 0;
		while ((*cmds)[i])
		{
			if ((*cmds)[i] == 7)
			{
				j = i;
				while ((*cmds)[j])
				{
					(*cmds)[j] = (*cmds)[j + 1];
					j++;
				}
			}
			i++;
		}
		cmds++;
	}
}

void	setup_path_cmd(t_pipex *p, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	handle_cmd(cmd);
	p->cmds = ft_split(cmd, 7);
	remove_symbols(p->cmds);
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

void	handle_cmd(char *cmd)
{
	int		i;
	char	*sq;
	
	i = 0;
	sq = NULL;
	while (cmd[i])
	{
		if (cmd[i] == 39 && cmd[i - 1] != 92)
		{
			sq = ft_strchr(&cmd[++i], 39);
			while (sq && (sq - &cmd[i]) - 1 == 92)
			{
				i += (sq - &cmd[i]) + 1;
				sq = ft_strchr(&cmd[i], 39);
			}
		}
		if (cmd[i] == 34 && cmd[i - 1] != 92)
		{
			sq = ft_strchr(&cmd[++i], 34);
			while (sq && (sq - &cmd[i]) - 1 == 92)
			{
				i += (sq - &cmd[i]) + 1;
				sq = ft_strchr(&cmd[i], 34);
			}
		}
		if (cmd[i] == ' ')
			cmd[i] = 7;
		i++;
	}
}