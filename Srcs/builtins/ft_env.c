/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:15 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:37:17 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	ft_env(int argc, char **argv, char **env)
{
	int	i;

	(void)argc;
	(void)argv;
	if (!env)
		return (1);
	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
	return (0);
}
