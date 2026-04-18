/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* master.c                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/18 13:01:42 by khisleem          #+#    #+#             */
/* Updated: 2026/04/18 13:34:28 by khisleem         ###   ########.fr       */
/* */
/* ************************************************************************** */
#include "team.h"

int	is_all_zeros(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	print_massive(int zeros, t_dict *dict)
{
	char	*key;
	int		i;

	key = malloc(sizeof(char) * (zeros + 2));
	if (!key)
		return ;
	key[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	ft_putstr(" ");
	ft_putstr(find_value(dict, key));
	free(key);
}

void	process_chunk(char *str, int len, int block_len, t_dict *dict)
{
	char	block[4];
	int		i;

	i = 0;
	while (i < block_len)
	{
		block[i] = str[i];
		i++;
	}
	block[i] = '\0';
	if (!is_all_zeros(block, block_len))
	{
		print_block(block, dict);
		if (len > 3)
			print_massive(len - block_len, dict);
		if (len - block_len > 0
			&& !is_all_zeros(str + block_len, len - block_len))
			ft_putstr(" ");
	}
}

void	master_solver(char *str, t_dict *dict)
{
	int	len;
	int	block_len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
	{
		ft_putstr(find_value(dict, "0"));
		return ;
	}
	while (len > 0)
	{
		block_len = len % 3;
		if (block_len == 0)
			block_len = 3;
		process_chunk(str, len, block_len, dict);
		str = str + block_len;
		len = len - block_len;
	}
}