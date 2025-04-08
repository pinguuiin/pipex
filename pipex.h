/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:19:34 by piyu              #+#    #+#             */
/*   Updated: 2025/04/08 05:19:40 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_path
{
	char	**cmd;
	char	**prefix;
	char	*path;
	char	*slash_cmd;
}	t_path;

void	error_exit(t_path *data, char *s, int sys_error_flag);
void	free_data(t_path *data);
void	execute_command(char *argv, char **envp);
#endif
