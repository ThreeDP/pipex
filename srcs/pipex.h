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
# include <stddef.h>

//extern char **environ;

// error messages 
# define ERR_CMD "command '%s' not found\n"
# define ERR_AGRS "invalid number of arguments\n"
# define ERR_PIPE "No such pipe\n"
# define ERR_IFILE "No such input file or directory\n"
# define ERR_OFILE "No such output file or directory\n"

typedef struct s_pipex
{
    pid_t   pid1;
    pid_t   pid2;
    int     pid_fd[2];
    int     infile;
    int     outfile;
    char    *prog;
    char    **paths;
    char    **cmds;
}               t_pipex;

// error functions
int         message(char *err);
void        merr(char *err);
size_t	    ft_strlen(const char *str);

#endif