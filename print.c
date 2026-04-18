#include "team.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*find_value(t_dict *dict, char *number_find)
{
	int	i;

	i = 0;
	while (dict[i].number != NULL)
	{
		if (ft_strcmp()dict[i].number, number_find == 0)
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
	}
	free(dict);
}