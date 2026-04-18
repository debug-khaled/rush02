#include "team.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;

	if (argc == 2)
	{
		dict_path = "dict.name";
		number = argv[1];
	}
// بهاي الحالة يعني بنكون حطينا الديكشنري الجديد الي نشتغل عليه
	else if (argc == 3)
	{
		dict_path = argv[1];
		number = argv[2];
	}
	else
	{
		putstr("Error\n");
		return (1);
	}
	return (0);
}
















