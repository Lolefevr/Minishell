/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_macros.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:33:14 by lolefevr          #+#    #+#             */
/*   Updated: 2023/08/18 14:33:15 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MACROS_H
# define MINISHELL_MACROS_H

# define OPERANDS_COUNT 12
# define OPERANDS "| || & && < > \\ ' \" << >>"
# define PIPE "|"
# define AND "&&"
# define OR "||"
# define DOL "$"
# define DOL_DOL "$$"
# define REDIR_IN "<"
# define REDIR_OUT ">"
# define REDIR_APPEND ">>"
# define REDIR_HERE_DOC "<<"
# define BACKSLASH "\\"
# define SIMPLE_QUOTE "'"
# define DOUBLE_QUOTE "\""

#endif
