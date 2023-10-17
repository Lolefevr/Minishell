/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublquote_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:38:39 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:38:41 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	doublquote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((int)str[i] == 34)
			return (i);
		i++;
	}
	return (-1);
}
