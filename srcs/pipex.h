/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 18:56:32 by dapaulin         ###   ########.fr       */
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

// chars
# define SIMPLEQUOTES 39
# define QUOTES 34
# define BACKSPACE 92
# define NOPRINT 7

// error messages 
# define ERR_CMD "command '%s' not found\n"
# define ERR_AGRS "invalid number of arguments\n"
# define ERR_PIPE "No such pipe\n"
# define ERR_IFILE "No such input file or directory\n"
# define ERR_OFILE "No such output file or directory\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pid_fd[2];
	int		infile;
	int		outfile;
	char	*prog;
	char	**paths;
	char	**cmds;
}			t_pipex;

// Error functions
int			message(char *err);
void		merr_msg(char *err);
void		merr(int err);
void		print_merr(t_pipex *p, int code);
void		err_msg_full(t_pipex *p, int code);
// Utils
char		**split_paths(char **env);
void		start_pipex(t_pipex *p, int ac, char **av, char **env);
void		clear_pipex(t_pipex *p);
void		setup_path_cmd(t_pipex *p, char *cmd);
// Utils 2
int			count_quotes(char *cmd);
void		make_clen_cmd(char *cmd, char *str);
void		remove_symbols(char **cmds);
void		check_quotes(char *cmd, int *i, int quotes);
void		handle_cmd(char *cmd);
// Pids
void		close_fds(t_pipex *p);
void		run_execve(t_pipex *p, char **env);
int			first_pid(t_pipex *p, char **env, char *cmd);
int			second_pid(t_pipex *p, char **env, char *cmd);
#endif