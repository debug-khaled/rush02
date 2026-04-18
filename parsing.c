/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:41:01 by khisleem          #+#    #+#             */
/*   Updated: 2026/04/18 20:41:05 by khisleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "team.h"

int	count_lines(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

char	*ft_strndup(char *str, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	extract_line_data(t_dict *dict, char *buffer, int *i, int j)
{
	int	start;

	start = *i;
	while (buffer[*i] >= '0' && buffer[*i] <= '9')
		(*i)++;
	dict[j].number = ft_strndup(&buffer[start], *i - start);
	while (buffer[*i] == ' ')
		(*i)++;
	if (buffer[*i] == ':')
		(*i)++;
	while (buffer[*i] == ' ')
		(*i)++;
	start = *i;
	while (buffer[*i] && buffer[*i] != '\n')
		(*i)++;
	dict[j].word = ft_strndup(&buffer[start], *i - start);
}

t_dict	*parse(char *buffer)
{
	t_dict	*dict;
	int		i;
	int		j;

	dict = malloc(sizeof(t_dict) * (count_lines(buffer) + 1));
	if (!dict)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i])
	{
		while (buffer[i] == '\n')
			i++;
		if (!buffer[i])
			break ;
		extract_line_data(dict, buffer, &i, j);
		j++;
	}
	dict[j].number = NULL;
	dict[j].word = NULL;
	return (dict);
}
