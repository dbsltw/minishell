/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:02:03 by akkim             #+#    #+#             */
/*   Updated: 2026/02/07 17:16:42 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char **envp, char *str)
{
	char	*find;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (ft_strncmp(envp[i], str, len) != 0)
		i++;
	find = ft_strdup(envp[i] + len + 1);
	return (find);
}

// env 파싱 파트

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	ft_printf("%s", get_env_value(envp, "USER"));
	// mini_echo("hello\n", envp);
}
