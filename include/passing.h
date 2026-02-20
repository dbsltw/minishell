/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:00:44 by akkim             #+#    #+#             */
/*   Updated: 2026/02/20 19:46:43 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSING_H
# define PASSING_H

# include "minishell.h"

typedef struct l_simple_command
{
	char	*cmd;
	char	**args;
	//	Redrect *redirects
}	t_simple_command;

t_simple_command	*passing_command(char *line);
void	builin_handler(t_info_env *env, t_simple_command *simple_command);

#endif