/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:02:03 by akkim             #+#    #+#             */
/*   Updated: 2026/02/10 19:58:54 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"

int	main(int argc, char **argv, char **envp)
{
	t_info_env	env;

	(void)argc;
	(void)argv;
	init_env(&env, envp);
	mini_export(&env, NULL);
	ft_printf("%s\n", get_env_val(env.head, "NULL"));
	// ft_printf("%s\n", get_env_val(env.head, "USER"), ); // test
	all_free_env(env.head);
}
