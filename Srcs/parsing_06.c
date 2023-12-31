/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_06.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:45:35 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:45:37 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	is_quote(char *argv)
{
	if (argv[0] == '\'')
		return (simplquote(argv + 1));
	else if (argv[0] == '"')
		return (doublquote(argv + 1));
	return (-1);
}

int	is_quote_zero(char *argv)
{
	int	i;

	i = 1;
	if (argv[0] == '\'')
	{
		while (argv[i])
		{
			if ((int)argv[i] == 39)
				return (i);
			i++;
		}
	}
	else if (argv[0] == '"')
	{
		while (argv[i])
		{
			if ((int)argv[i] == 34)
				return (i);
			i++;
		}
	}
	return (0);
}

int	verifquote(char *argv)
{
	if (argv[0] == '\'' || argv[0] == '\"')
		return (1);
	return (0);
}

int	next_pipe(t_par **p, int nb_cmd)
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (p[j] && res != nb_cmd + 1)
	{
		if (p[j]->type == 1)
			res++;
		j++;
	}
	if (p[j] && p[j]->type == 1)
		j++;
	return (j);
}

int	real_cmd(t_par **par)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (par[i])
	{
		if (par[i]->type == 1)
			j++;
		i++;
	}
	return (j);
}
