/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:57:36 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/29 15:57:36 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

int message(char *err)
{
    write(2, err, ft_strlen(err));
    return (1);
}

void    merr(char *err)
{
    perror(err);
    exit(1);
}