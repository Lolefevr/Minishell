/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_shlvl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:29 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:44:30 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	new_shlvl(char *env)
{
	int	sh_atoi;

	sh_atoi = ft_atoi(env + 6);
	if (sh_atoi <= 9)
		*(env + 6) += 1;
}

void	modif_shlvl(char **env)
{
	int	i;

	i = 0;
	if (!*env)
		return ;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
		{
			new_shlvl(env[i]);
			break ;
		}
		i++;
	}
}
