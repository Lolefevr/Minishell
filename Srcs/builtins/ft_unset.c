/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:54 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:38:00 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

/* Function to delete a variable from its shell environment
 *
 * @param char **argv	-> pointer to the arguments array
 * @param t_env *env	-> pointer to the shell environment to modify
 * @return int			-> function exit code
 */
int	ft_unset(char **argv, t_env **env)
{
	t_env	*var;

	if (!argv || !*argv)
		return (SH_ERROR);
	if (!*env)
		return (SH_SUCCESS);
	while (*++argv)
	{
		var = get_env_var(*env, *argv);
		if (var)
			del_env_var(var, var->prev, var->next);
	}
	return (SH_SUCCESS);
}
