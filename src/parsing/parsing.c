/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkim <akkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:32:27 by akkim             #+#    #+#             */
/*   Updated: 2026/02/27 15:25:51 by akkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minishell.h"
/*
	parsing 구조 정리
	1. "" 나 ''에 맞춰서 검사한다.
		- 끝나지 않으면 "dquote>" 출력하여 readline으로 받아서 합쳐야함
	2. 받은 전체를 command_line 구조체로 분리한다. && 와 || 를 확인하고 분리해야함
	3. 
*/

	// "", '' 검사 함수
	// "" or ''가 있고 끝나는 지 검사하기
	// 닫히지 않았으면 "dquote>" 출력하여 readline으로 받아서 합치기
	// && 나 ||가 있으면 기준으로 command line이 분리하기
	// 다시 parsing command하기
	// pipeline으로 쪼개야함
	// command_line 분리가 잘 되는지 확인할 것

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	h;
	int	n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	h = 0;
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && haystack[h + n] != '\0')
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)&haystack[h]);
		}
		h++;
	}
	return (0);
}

char	*ft_strrchr(const char *str, int ch)
{
	char	*last;
	int		i;

	last = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)ch)
		{
			last = (char *)&str[i];
		}
		i++;
	}
	if ((unsigned char)ch == '\0')
	{
		return ((char *)&str[i]);
	}
	return (last);
}

char	*find_next_operator(char *line)
{
	char	*and_ptr;
	char	*or_ptr;

	and_ptr = ft_strstr(line, "&&");
	or_ptr = ft_strstr(line, "||");
	if (and_ptr != 0 && or_ptr != 0)
	{
		if (and_ptr < or_ptr)
			return (and_ptr);
		return (or_ptr);
	}
	if (and_ptr != 0)
		return (and_ptr);
	return (or_ptr);
}
t_simple_command	*parsing_simple_command()
{

}

// p_op : pipe operator
t_pipeline	*parsing_pipeline(char *line)
{
	t_pipeline	*pipeline;
	char		*tmp;
	char		*p_op;

	if (!line)
		return (NULL);
	pipeline = malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->next = 0;
	p_op = ft_strrchr(line, '|');
	if (p_op != NULL)
	{
		tmp = ft_substr(line, 0, p_op - line);
		pipeline->next = parsing_command_line(ft_substr(line, 0, p_op - line));
		free(tmp);
		pipeline->simple_command- parsing_simple()
	}
}

t_command_line	*parsing_command_line(char *line)
{
	t_command_line	*command_line;
	char			*comm;
	char			*tmp;

	if (!line)
		return (NULL);
	command_line = malloc(sizeof(t_command_line));
	if (!command_line)
		return (NULL);
	command_line->next = 0;
	command_line->comm_oper = 0;
	comm = find_next_operator(line);
	if (comm != 0)
	{
		command_line->comm_oper = comm[0];
		tmp = ft_substr(line, 0, comm - line);
		command_line->pipeline = parsing_pipeline(tmp);
		free(tmp);
		tmp = ft_strdup(comm + 2);
		command_line->next = parsing_command_line(tmp);
		free(tmp);
	}
	else
		command_line->pipeline = parsing_pipeline(ft_strdup(line));
	return (command_line);
}
