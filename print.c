/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:43:07 by khisleem          #+#    #+#             */
/*   Updated: 2026/04/18 14:43:24 by khisleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "team.h"

char	*find_value(t_dict *dict, char *number_find)
{
	int	i;

	i = 0;
	while (dict[i].number != NULL)
	{
		if (ft_strcmp(dict[i].number, number_find) == 0)
			return (dict[i].word);
		i++;
	}
	return (NULL);
}

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	if (!dict)
		return ;
	while (dict[i].number != NULL)
	{
		free(dict[i].number);
		free(dict[i].word);
		i++;
	}
	free(dict);
}
