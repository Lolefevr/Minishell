/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:42 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:39:43 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	free_and_return(void)
{
	free_trinity();
	if (g_shell_data)
		free_data(g_shell_data);
	set_termios_mode(TERMIOS_UNMUTE_CTRL);
}
