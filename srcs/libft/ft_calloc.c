/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:00:12 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 16:13:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	ptr = NULL;
	if (nmemb >= ~(1 << 31) || size >= ~(1 << 31) || !nmemb || !size)
		return (0);
	len = nmemb * size;
	ptr = (unsigned char *) malloc(len);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, len);
	return (ptr);
}
