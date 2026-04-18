/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khisleem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:13:18 by khisleem          #+#    #+#             */
/*   Updated: 2026/04/18 21:13:18 by khisleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEAM_H
# define TEAM_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*number;
	char	*word;
}	t_dict;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		file_size(char *dict_path);
char	*read_dict_file(char *dict_path);
int		count_lines(char *buffer);
char	*ft_strndup(char *str, int n);
t_dict	*parse(char *buffer);
int		ft_strcmp(char *s1, char *s2);
char	*find_value(t_dict *dict, char *number_to_find);
void	free_dict(t_dict *dict);
void	print_unit(char c, t_dict *dict);
void	print_ten(char c, t_dict *dict);
void	print_teen(char c1, char c2, t_dict *dict);
void	print_two_digits(char *str, t_dict *dict);
void	print_block(char *block, t_dict *dict);
int		is_all_zeros(char *str, int len);
void	print_massive(int zeros, t_dict *dict);
void	master_solver(char *str, t_dict *dict);

#endif
