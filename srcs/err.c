/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:57:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/25 19:23:42 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

int message(char *err)
{
    write(2, err, ft_strlen(err));
    return (1);
}

void    merr_msg(char *err)
{
    message(err);
    exit(1);
}

void    merr(int err)
{
    perror("\nERROR");
    exit(err);
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
			if (sq)
				i += (sq - &cmd[i]) + 1;
		}
		if (cmd[i] == ' ')
			cmd[i] = 7;
		i++;
	}
}