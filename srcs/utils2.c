/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:49:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 18:17:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

int	count_quotes(char *cmd)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (cmd[i])
	{
		if (!((cmd[i] == SIMPLEQUOTES || cmd[i] == QUOTES) && \
		cmd[i - 1] != BACKSPACE))
			c++;
		i++;
	}
	return (c);
}

void	make_clen_cmd(char *cmd, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (!((cmd[i] == SIMPLEQUOTES || cmd[i] == QUOTES) && \
		cmd[i - 1] != BACKSPACE))
			str[j++] = cmd[i];
		i++;
	}
}

void	remove_symbols(char **cmds)
{
	char	*str;

	str = NULL;
	while (*cmds)
	{
		str = ft_calloc(sizeof(char), count_quotes(*cmds) + 1);
		make_clen_cmd(*cmds, str);
		if (*cmds)
			free(*cmds);
		*cmds = str;
		cmds++;
	}
}

void	check_quotes(char *cmd, int *i, int quotes)
{
	char	*sq;

	sq = NULL;
	if (cmd[*i] == quotes && cmd[*i - 1] != BACKSPACE)
	{
		*i += 1;
		sq = ft_strchr(&cmd[*i], quotes);
		while (sq && (sq - &cmd[*i]) - 1 == BACKSPACE)
		{
			*i += (sq - &cmd[*i]) + 1;
			sq = ft_strchr(&cmd[*i], quotes);
		}
		if (sq)
			*i += (sq - &cmd[*i]) + 1;
	}
}

void	handle_cmd(char *cmd)
{
	int		i;
	char	*sq;

	i = 0;
	sq = NULL;
	while (cmd[i])
	{
		check_quotes(cmd, &i, SIMPLEQUOTES);
		check_quotes(cmd, &i, QUOTES);
		if (cmd[i] == ' ')
			cmd[i] = NOPRINT;
		i++;
	}
}
