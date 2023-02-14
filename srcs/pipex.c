/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/14 16:19:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/minilibft.h"

int main(int argc, char **argv)
{
	t_pipex     *p;
	int			status;
	int			d;
	extern char **environ;

	if (argc != 5)
		return (message(ERR_AGRS));
	p = (t_pipex *) malloc(sizeof(t_pipex));
	start_pipex(p, argc, argv, environ);
	p->pid1 = fork();
	first_pid(p, environ, argv[2]);
	p->pid2 = fork();
	second_pid(p, environ, argv[3]);	
	close(p->pid_fd[0]);
	close(p->pid_fd[1]);
	waitpid(p->pid1, &status, 0);
	waitpid(p->pid2, &status, 0);
	clear_pipex(p);
	return (WEXITSTATUS(status));
}
