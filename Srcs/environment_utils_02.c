/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:13 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:39:15 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/* Function to return a shell environment's data as a strings array
 *
 * @param t_env *env_list	-> pointer to the list to convert
 * @return char **			-> pointer to the converted strings array
 */
char	**env_to_str_tab(t_env **env_list)
{
	int		i;
	char	**envp;
	t_env	*start;
	t_env	*temp;

	if (!env_list)
		return (NULL);
	start = *env_list;
	temp = *env_list;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	envp = (char **) ft_calloc((i + 1), sizeof(char *));
	if (!envp)
		return (NULL);
	envp = env_to_str_tab_02(envp, start);
	return (envp);
}

char	**env_to_str_tab_02(char **envp, t_env *start)
{
	int	i;

	i = 0;
	while (start)
	{
		envp[i++] = ft_strdup(start->display);
		if (!envp[i - 1])
			return (free_str_tab((void **)&envp), NULL);
		start = start->next;
	}
	return (envp);
}

/* Function to get the pointer to an environment's variable structure
 * with a given name
 *
 * @param t_env *env_list	-> pointer to the environment linked list
 * @param char *var_name	-> pointer to the variable name to find
 * @return t_env *			-> pointer to the retrieved variable structure
 */
t_env	*get_env_var(t_env *env_list, char *var_name)
{
	int	name_len;

	if (!env_list || !var_name)
		return (NULL);
	name_len = ft_strlen(var_name);
	while (env_list && ft_strncmp(env_list->name, var_name, name_len))
		env_list = env_list->next;
	return (env_list);
}

/* Function to update a shell variable structure's value with a new one
 *
 * @parent_function update_env_var
 * @param t_env *env_var	-> pointer to the variable structure to update
 * @param char *value		-> pointer to the update value
 * @param int mode			-> update mode (SH_OVERWRITE/SH_ADDBACK/SH_ADDFRONT)
 * @return int				-> status code of the function
 */
int	update_env_value(t_env *env_var, char *value, int mode)
{
	char	*temp;

	if (!env_var->value || mode == SH_OVERWRITE)
	{
		safe_free((void **) &env_var->value);
		if (value)
			env_var->value = ft_strdup(value);
		else
			env_var->value = ft_strdup("");
	}
	else if (value)
	{
		temp = env_var->value;
		if (mode == SH_ADDFRONT)
			env_var->value = ft_strjoin(value, temp);
		else
			env_var->value = ft_strjoin(temp, value);
		free(temp);
	}
	if (!env_var->value)
		return (SH_ERROR);
	return (SH_SUCCESS);
}

/* Function to update a variable structure's value + display with a new value
 * mode(SH_OVERWRITE)	-> set the variable to the new value
 * mode(SH_ADDBACK)		-> concatenate the new value after the current value
 * mode(SH_ADDFRONT)	-> concatenate the new value before the current value
 *
 * @child_function update_env_value
 * @param t_env *env_var	-> pointer to the variable structure to update
 * @param char *value		-> pointer to the update value
 * @param int mode			-> update mode (SH_OVERWRITE/SH_ADDBACK/SH_ADDFRONT)
 * @return t_env *			-> pointer to the updated variable structure
 */
t_env	*update_env_var(t_env *env_var, char *value, int mode)
{
	char	*temp;

	if (!env_var)
		return (NULL);
	if (!value && mode != SH_OVERWRITE)
		return (env_var);
	if (update_env_value(env_var, value, mode) != SH_SUCCESS)
		return (NULL);
	safe_free((void **) &env_var->display);
	temp = ft_strjoin(env_var->name, "=");
	if (!temp)
		return (NULL);
	env_var->display = ft_strjoin(temp, env_var->value);
	free(temp);
	if (!env_var->display)
		return (NULL);
	return (env_var);
}
