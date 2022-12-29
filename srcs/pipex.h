/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:10 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/29 17:46:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// funcs write, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

// funcs waitpid, wait
# include <sys/wait.h>

// func perror
# include <stdio.h>

// func strerror
# include <string.h>

// funcs malloc, free, exit
# include <stdlib.h>

// funcs open, unlink
# include <fcntl.h>

// error messages 
# define ERR_CMD "command '%s' not found\n"
# define ERR_AGRS "invalid number of arguments\n"
# define ERR_INFILE "No such file or directory\n"

typedef 

// error functions
int         message(char *err);
void        merr(char *err);
size_t	    ft_strlen(const char *str);

#endif