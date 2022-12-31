/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:22:28 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/30 17:22:28 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	    *ft_strdup(const char *s);
size_t	    ft_strlen(const char *str);
size_t	    ft_strlcpy(char *dest, const char *src, size_t size);
void	    *ft_calloc(size_t nmemb, size_t size);
void	    *ft_memset(void *str, int c_fill, size_t n_bytes);
char	    **ft_split(char const *s, char c);
char	    *ft_strchr(const char *str, int c);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_strndup(const char *s, size_t size);
int         ft_strncmp(const char *s1, const char *s2, size_t n);

#endif