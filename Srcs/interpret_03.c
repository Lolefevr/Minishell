/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:40:49 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:40:51 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*get_path(char *cmd, t_env *env)
{
	char	*var;
	char	**path;
	char	*path_cmd;

	var = ft_getenv(env, "PATH");
	if (!var)
		return (NULL);
	path = ft_split(var, ':');
	path_cmd = get_path_cmd(path, cmd);
	free_str_tab((void **)path);
	return (path_cmd);
}

char	*get_path_cmd(char **path, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	*tmp;

	if (cmd[0] == '.' || cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i++], "/");
		if (!tmp)
			return (NULL);
		path_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path_cmd)
			return (NULL);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
	}
	return (NULL);
}

void	piper(t_env *env, t_rinity *cmd_struct)
{
	int		fd[2];
	pid_t	pid;

	if (cmd_struct->builtin >= 0 && cmd_struct->builtin <= 3)
		return ;
	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		continue_child(cmd_struct, fd, env);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		g_shell_data->exit_code = 0;
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	continue_child(t_rinity *cmd_struct, int *fd, t_env *env)
{
	redirect(cmd_struct, 0);
	redirect(cmd_struct, 1);
	close(fd[0]);
	if (!cmd_struct->file_out)
		dup2(fd[1], STDOUT_FILENO);
	if (cmd_struct->builtin > 3)
		execute_builtin2(cmd_struct, cmd_struct->builtin, env);
	else
		execute_cmd(env, cmd_struct);
}

void	execute_builtin2(t_rinity *cmd_struct, int builtin, t_env *env)
{
	if (builtin == 5 && ft_strlen(cmd_struct->cmd[0]) == 4)
		ft_echo(lentab(cmd_struct->cmd), cmd_struct->cmd);
	else if (builtin == 6 && ft_strlen(cmd_struct->cmd[0]) == 3)
		ft_pwd(lentab(cmd_struct->cmd), cmd_struct->cmd);
	else if (builtin == 4 && ft_strlen(cmd_struct->cmd[0]) == 3)
		ft_env(lentab(cmd_struct->cmd), cmd_struct->cmd, env_to_str_tab(&env));
}
