#include "rush.h"

char	**ft_parse_numbers(char *full_dict)
{
	char	*nb_d;
	int		i;
	int		j;
	char	**result;

	result = NULL;
	nb_d = malloc(1024);
	if (!nb_d)
		return (NULL);
	i = 0;
	j = 0;
	while (full_dict[j])
	{
		while (full_dict[j] >= '0' && full_dict[j] <= '9')
			nb_d[i++] = full_dict[j++];
		nb_d[i++] = ' ';
		while (full_dict[j] && !(full_dict[j] >= '0' && full_dict[j] <= '9'))
			j++;
	}
	nb_d[i] = '\0';
	result = ft_split(nb_d, ' ');
	free(nb_d);
	return (result);
}

char	**ft_parse_words(char *full_dict)
{
	char	*wd_d;
	int		i;
	int		j;
	char	**result;

	result = NULL;
	wd_d = malloc(1024);
	if (!wd_d)
		return (NULL);
	i = 0;
	j = 0;
	while (full_dict[j])
	{
		while (full_dict[j] && full_dict[j] != ':')
			j++;
		while (full_dict[j] == ' ' || full_dict[j] == ':')
			j++;
		while (full_dict[j] && full_dict[j] != '\n')
			wd_d[i++] = full_dict[j++];
		wd_d[i++] = ' ';
	}
	wd_d[i] = '\0';
	result = ft_split(wd_d, ' ');
	free(wd_d);
	return (result);
}

void	ft_parse(int fd, char *nb)
{
	char	*full_dict;
	char	**nb_d;
	char	**wd_d;

	full_dict = ft_parse_dict(fd);
	nb_d = ft_parse_numbers(full_dict);
	wd_d = ft_parse_words(full_dict);
	free(full_dict);
	alg_base(nb_d, wd_d, nb);
}

static void	ft_combine(char *buffer, char **dict)
{
	char	*tmp;

	if (!*dict)
		*dict = ft_strdup(buffer);
	else if (buffer)
	{
		tmp = *dict;
		*dict = ft_strjoin(*dict, buffer);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
}

char	*ft_parse_dict(int fd)
{
	char	*dict;
	int		bytes;
	char	*buffer;
	int		i;

	dict = NULL;
	i = 0;
	bytes = 1;
	buffer = malloc(2);
	if (!buffer)
		return (NULL);
	while (bytes == read(fd, buffer, 1))
	{
		if (bytes < 1)
			break ;
		buffer[1] = '\0';
		ft_combine(buffer, &dict);
		i++;
	}
	dict[i] = '\0';
	free(buffer);
	return (dict);
}
