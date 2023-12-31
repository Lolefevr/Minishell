/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:46:31 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:46:32 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_strjoin_plus(char *dest, char *src)
{
	if (!dest || !src)
		return (ft_strdup((void *)((uintptr_t)(void *) src * (1 && src)
			+ (uintptr_t)(void *) dest * (1 && dest))));
	return (ft_strjoin(dest, src));
}

char	*ft_free_strcat(char **dest, char *src, int start, int end)
{
	char	*temp;
	char	*temp2;

	temp = ft_substr(src, start, end - start);
	if (!temp)
		return (NULL);
	temp2 = ft_strjoin_plus(*dest, temp);
	free(temp);
	safe_free((void **) dest);
	if (!temp2)
		return (NULL);
	*dest = temp2;
	return (*dest);
}

void	print_str_tab(char **str_tab)
{
	if (!str_tab)
	{
		ft_fprintf(2, "NULL\n");
		return ;
	}
	while (*str_tab)
		ft_fprintf(2, "[%s] ", *str_tab++);
	ft_fprintf(2, "\n");
}
