/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:03 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/29 15:20:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void    start_pipex(t_pipex **p, int ac, char **av)
{
    (*p)->infile = open(av[1], O_RDONLY);
    if ((*p)->infile < 0)
        merr(ERR_IFILE);
    (*p)->outfile = open(av[1 - ac], O_TRUNC | O_CREAT | O_RDWR, 00644);
    if ((*p)->outfile < 0)
        merr(ERR_OFILE);
    if (pipe((*p)->pid_fd) < 0)
        merr(ERR_PIPE);
}

/*
void    first_pid(t_pipex **p, char **av)
{

}*/


int main(int argc, char **argv)
{
    t_pipex     *p;
    extern char **environ;

    if (argc != 5)
        return (message(ERR_AGRS));
    p = (t_pipex *) malloc(sizeof(t_pipex));
    start_pipex(&p, argc, argv);

    p->pid1 = fork();
    if (0 > p->pid1)
        return (2);
    if (p->pid1 == 0)
    {
        dup2(p->pid_fd[1], STDOUT_FILENO);
        close(p->pid_fd[0]);
        close(p->pid_fd[1]);
        execlp("ls", "ls", "-l", NULL);
        //dup2(STDOUT_FILENO, pid_fd[1]);
    }

    p->pid2 = fork();
    if (0 > p->pid2)
      return (3);
    if (p->pid2 == 0)
    {
        dup2(p->pid_fd[0], STDIN_FILENO);
        close(p->pid_fd[1]);
        dup2(p->outfile, 1);
        execlp("wc", "wc", "-l", NULL);
    }

    close(p->pid_fd[0]);
    close(p->pid_fd[1]);
    waitpid(p->pid1, NULL, 0);
    waitpid(p->pid2, NULL, 0);
    return 0;
}