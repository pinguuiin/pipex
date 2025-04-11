/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:18:32 by piyu              #+#    #+#             */
/*   Updated: 2025/04/08 05:18:40 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Store all allocated memory into a structure*/
static void	initialize_path(t_path *data)
{
	data->cmd = NULL;
	data->prefix = NULL;
	data->path = NULL;
	data->slash_cmd = NULL;
}

void	free_data(t_path *data)
{
	int	i;

	if (data == NULL)
		return ;
	if (data->cmd)
	{
		i = 0;
		while (data->cmd[i])
			free(data->cmd[i++]);
		free(data->cmd);
	}
	if (data->prefix)
	{
		i = 0;
		while (data->prefix[i])
			free(data->prefix[i++]);
		free(data->prefix);
	}
	if (data->path)
		free(data->path);
	if (data->slash_cmd)
		free(data->slash_cmd);
}

/*Find all environment paths and split them into a 2d array*/
static char	**find_path(t_path *data, char **envp)
{
	int		i;
	char	*ptr;
	char	**prefix;

	i = 0;
	while (envp[i])
	{
		ptr = ft_strnstr(envp[i], "PATH", 4);
		if (ptr)
			break ;
		i++;
	}
	if (!ptr)
		error_exit(data, "Command not found: PATH is incorrectly set", 127);
	ptr += 5;
	prefix = ft_split(ptr, ':');
	if (!prefix)
		error_exit(data, "Error allocating memory", 0);
	return (prefix);
}

/*Concatenate paths and filename and check the existence and
accessability of the target file*/
static char	*find_cmdfile(t_path *data, char *cmd, char **envp)
{
	int	i;

	i = 0;
	data->prefix = find_path(data, envp);
	data->slash_cmd = ft_strjoin("/", cmd);
	if (!data->slash_cmd)
		error_exit(data, "Error allocating memory", 0);
	while (data->prefix[i])
	{
		data->path = ft_strjoin(data->prefix[i], data->slash_cmd);
		if (!data->path)
			error_exit(data, "Error allocating memory", 0);
		if (access(data->path, F_OK) == 0)
		{
			if (access(data->path, X_OK) == -1)
				error_exit(data, cmd, 126);
			return (data->path);
		}
		free(data->path);
		data->path = NULL;
		i++;
	}
	error_exit(data, cmd, 127);
	return (NULL);
}

void	execute_command(char *argv, char **envp)
{
	t_path	data;
	char	*filepath;

	initialize_path(&data);
	data.cmd = ft_split(argv, ' ');
	if (!data.cmd)
		error_exit(&data, "Error allocating memory", 0);
	else if (!data.cmd[0])
		error_exit(&data, "Error: Empty command input", 0);
	if (ft_isalpha(data.cmd[0][0]))
		filepath = find_cmdfile(&data, data.cmd[0], envp);
	else
	{
		filepath = data.cmd[0];
		if (access(filepath, F_OK) == 0 && access(filepath, X_OK) == -1)
			error_exit(&data, filepath, 126);
		if (access(filepath, F_OK | X_OK) != 0)
			error_exit(&data, filepath, 127);
	}
	if (execve(filepath, data.cmd, envp) == -1)
		error_exit(&data, "Error executing command", 1);
}
