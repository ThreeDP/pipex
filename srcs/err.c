/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:57:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 18:27:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

int	message(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	merr_msg(char *err)
{
	message(err);
	exit(1);
}

void	merr(int err)
{
	perror("\nERROR");
	exit(err);
}

void	print_merr(t_pipex *p, int code)
{
	if (p)
		free(p);
	merr(code);
}

void	err_msg_full(t_pipex *p, int code)
{
	int	i;

	i = 0;
	while ((p->cmds)[i])
		free((p->cmds)[i++]);
	clear_pipex(p);
	perror("ERROR");
	exit(code);
}
