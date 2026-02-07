/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:13:55 by akkim             #+#    #+#             */
/*   Updated: 2026/02/07 19:54:46 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"

void	mini_export(t_info_env *env, char *str)
{
	t_env	*node;
	char	*eq;
	char	*key;
	char	*value;

	eq = ft_strchr(str, '=');
	key = ft_substr(str, 0, eq - str);
	value = ft_strdup(eq + 1);
	node = find_env_node(env->head, key);
	if (node != NULL)
		node->value = value;
	else
	{
		node = new_env_node(key, value);
		env_add_back(&env->head, node);
	}
}