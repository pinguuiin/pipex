/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:13:33 by piyu              #+#    #+#             */
/*   Updated: 2025/04/07 19:32:22 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Free all allocated memory before exit*/
void	error_exit(t_path *data, char *s, int sys_error_flag)
{
	free_data(data);
	if (sys_error_flag == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(EXIT_FAILURE);
}

static void	child_one(int *pipefd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "Couldn't open the infile", 1);
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd);
	close(pipefd[1]);
	execute_command(argv[2], envp);
}

static void	child_two(int *pipefd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_exit(NULL, "Couldn't write in the outfile", 1);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipefd[0]);
	execute_command(argv[3], envp);
}

/*The process waiting for all child processes to be done and return the
exit status of the second child process (on the right of the pipe)*/
static int	parent(pid_t pid)
{
	int	i;
	int	wstatus;
	int	exit_status;

	i = 0;
	while (i++ < 2)
	{
		if (wait(&wstatus) == pid)
			exit_status = WEXITSTATUS(wstatus);
	}
	return (exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 0;
	if (argc != 5)
		error_exit(NULL, "Error in input: Number of arguments incorrect", 0);
	if (pipe(pipefd) == -1)
		error_exit(NULL, "Error creating pipe", 1);
	while (i++ < 2)
	{
		pid = fork();
		if (pid == -1)
			error_exit(NULL, "Error creating child process", 1);
		if (i == 1 && pid == 0)
			child_one(pipefd, argv, envp);
		if (i == 2 && pid == 0)
			child_two(pipefd, argv, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (parent(pid));
}
