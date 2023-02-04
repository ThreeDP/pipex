/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:57:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/31 00:45:36 by dapaulin         ###   ########.fr       */
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
