/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:22:55 by khisleem          #+#    #+#             */
/*   Updated: 2026/04/18 12:59:00 by khisleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "team.h"

void	print_unit(char c, t_dict *dict)
{
	char	key[2];

	if (c == '0')
	{
		return ;
	}
	key[0] = c;
	key[1] = '\0';
	ft_putstr(find_value(dict, key));
}

void	print_ten(char c, t_dict *dict)
{
	char	key[3];

	if (c == '0')
		return ;
	key[0] = c;
	key[1] = '0';
	key[2] = '\0';
	ft_putstr(find_value(dict, key));
}

void	print_teen(char c1, char c2, t_dict *dict)
{
	char	key[3];

	key[0] = c1;
	key[1] = c2;
	key[2] = '\0';
	ft_putstr(find_value(dict, key));
}

void	print_two_digits(char *str, t_dict *dict)
{
	if (str[0] == '1')
		print_teen(str[0], str[1], dict);
	else
	{
		print_ten(str[0], dict);
		if (str[0] != '0' && str[1] != '0')
			ft_putstr("-");
		print_unit(str[1], dict);
	}
}

void	print_block(char *block, t_dict *dict)
{
	int	len;

	len = ft_strlen(block);
	if (len == 3)
	{
		if (block[0] != '0')
		{
			print_unit(block[0], dict);
			ft_putstr(" ");
			ft_putstr(find_value(dict, "100"));
			if (block[1] != '0' || block[2] != '0')
				ft_putstr(" ");
		}
		print_two_digits(block +1, dict);
	}
	else if (len == 2)
		print_two_digits(block, dict);
	else if (len == 1)
		print_unit(block[0], dict);
}
