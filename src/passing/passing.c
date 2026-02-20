/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:32:27 by akkim             #+#    #+#             */
/*   Updated: 2026/02/20 19:45:34 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"
#include "minishell.h"

// static char	*ft_split_one(char const *s, char c)
// {
// 	char	*str;
// 	int		i;
// 	int		len;
// 	int		j;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] == c)
// 		i++;
// 	len = 0;
// 	while (s[i + len] && s[i + len] != c)
// 		len++;
// 	if (len == 0)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	j = 0;
// 	while (j < len)
// 	{
// 		str[j] = s[i + j];
// 		j++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// static int	count_word(char	const *s, char c)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i])
// 		{
// 			count++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 		}
// 	}
// 	return (count);
// }

// static int	len_word(char *s, char c)
// {
// 	int	len;

// 	len = 0;
// 	while (s[len] && s[len] != c)
// 		len++;
// 	return (len);
// }

// static char	**free_split(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str && str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free (str);
// 	return (NULL);
// }

// static char	**ft_split_pass(char const *s, char c)
// {
// 	char	**str;
// 	int		i;
// 	int		j;
// 	int		words;

// 	words = count_word(s, c);
// 	str = (char **)malloc((words + 1) * sizeof(char *));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (*s && i < words)
// 	{
// 		while (*s == c)
// 			s++;
// 		str[i] = (char *)malloc((len_word((char *)s, c) + 1) * sizeof(char));
// 		if (!str[i])
// 			return (free_split(str));
// 		j = 0;
// 		while (*s != c && *s)
// 			str[i][j++] = *s++;
// 		str[i][j] = '\0';
// 		i++;
// 	}
// 	str[i] = NULL;
// 	return (str);
// }

t_simple_command	*passing_command(char *line)
{
	t_simple_command	*simple_command;
	char				**split;

	simple_command = (t_simple_command *)malloc(sizeof(t_simple_command));
	if (!simple_command)
		return (NULL);
	split = ft_split(line, ' ');
	simple_command->cmd = split[0];
	simple_command->args = split;

	return (simple_command);
}
