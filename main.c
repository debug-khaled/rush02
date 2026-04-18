/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:39:14 by khisleem          #+#    #+#             */
/*   Updated: 2026/04/18 20:39:19 by khisleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "team.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv, char **dict_path, char **number)
{
	if (argc == 2)
	{
		*dict_path = "numbers.dict";
		*number = argv[1];
	}
	else if (argc == 3)
	{
		*dict_path = argv[1];
		*number = argv[2];
	}
	else
		return (0);
	if (!is_valid(*number))
		return (0);
	return (1);
}

t_dict	*process_dict(char *dict_path)
{
	char	*buffer;
	t_dict	*dict;

	buffer = read_dict_file(dict_path);
	if (!buffer)
		return (NULL);
	dict = parse(buffer);
	free(buffer);
	return (dict);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;
	t_dict	*dict;

	if (!check_args(argc, argv, &dict_path, &number))
	{
		ft_putstr("Error\n");
		return (1);
	}
	dict = process_dict(dict_path);
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	while (number[0] == '0' && number[1] != '\0')
		number++;
	master_solver(number, dict);
	ft_putstr("\n");
	free_dict(dict);
	return (0);
}
