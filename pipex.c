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
	if (sys_error_flag == 0)
	{
		ft_putendl_fd(s, STDERR_FILENO);
		free_data(data);
		exit(EXIT_FAILURE);
	}
	if (sys_error_flag == 127 && ft_strnstr(s, "PATH", 25))
	{
		ft_putendl_fd(s, STDERR_FILENO);
		free_data(data);
		exit(sys_error_flag);
	}
	else
	{
		perror(s);
		free_data(data);
		exit(sys_error_flag);
	}
}

static void	child_one(int *pipefd, char **argv, char **envp)
{
	int	fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(pipefd[1]);
		error_exit(NULL, argv[1], 1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd);
	close(pipefd[1]);
	execute_command(argv[2], envp);
}

static void	child_two(int *pipefd, char **argv, char **envp)
{
	int	fd;

	close(pipefd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(pipefd[0]);
		error_exit(NULL, argv[4], 1);
	}
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
		error_exit(NULL, "Invalid input: Number of arguments incorrect", 0);
	if (pipe(pipefd) == -1)
		error_exit(NULL, "Pipe failed", 1);
	while (i++ < 2)
	{
		pid = fork();
		if (pid == -1)
			break ;
		if (i == 1 && pid == 0)
			child_one(pipefd, argv, envp);
		if (i == 2 && pid == 0)
			child_two(pipefd, argv, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	if (pid == -1)
		error_exit(NULL, "Fork failed", 0);
	return (parent(pid));
}
