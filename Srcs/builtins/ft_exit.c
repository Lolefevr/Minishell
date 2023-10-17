/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:25 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:37:27 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	ft_exit(void)
{
	free_trinity();
	safe_free((void **)&g_shell_data->path);
	if (g_shell_data->env)
		free_data(g_shell_data);
	set_termios_mode(TERMIOS_UNMUTE_CTRL);
	exit(EXIT_SUCCESS);
}
