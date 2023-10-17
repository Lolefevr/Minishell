/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:45 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:37:47 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	ft_pwd(int argc, char **argv)
{
	char	buffer[512];

	(void)argc;
	(void)argv;
	if (getcwd(buffer, sizeof(buffer)) != NULL)
		printf("Le répertoire de travail actuel est : %s\n", buffer);
	else
	{
		perror("Erreur lors de l'appel à getcwd");
		return (1);
	}
	return (0);
}
