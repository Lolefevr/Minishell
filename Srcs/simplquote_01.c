/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplquote_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:46:41 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:46:43 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	simplquote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((int)str[i] == 39)
			return (i);
		i++;
	}
	return (-1);
}
