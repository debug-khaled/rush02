#ifndef TEAM_H
# define TEAM_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_dict
{
	char	*number;
	chat	*word;
} t_dict;
int	file_size(char *dict_path);
char	read_file(char *dict_path);
int	count_lines(char *buffer);
char	*ft_strndup(char *str, int n);
t_dict	*parse(char *buffer);
int	ft_strcmp(char *s1, char *s2);
char	*find_value(t_dict *dict, char *number_to_find);
void	free_dict(t_dict *dict);
#endif