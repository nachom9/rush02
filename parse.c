#include "rush.h"

char	**ft_parse_numbers(char *full_dict)
{
	char	*numbers_dict;
	int		i;
	int		j;
	char	**result;

	result = NULL;
	numbers_dict = malloc(1024);
	if (!numbers_dict)
		return (NULL);
	i = 0;
	j = 0;
	while (full_dict[j])
	{
		while (full_dict[j] >= '0' && full_dict[j] <= '9')
			numbers_dict[i++] = full_dict[j++];
		numbers_dict[i++] = ' ';
		while (full_dict[j] && !(full_dict[j] >= '0' && full_dict[j] <= '9'))
			j++;
	}
	numbers_dict[i] = '\0';
	result = ft_split(numbers_dict, ' ');
	free(numbers_dict);
	return (result);
}

char	**ft_parse_words(char *full_dict)
{
	char	*words_dict;
	int		i;
	int		j;
	char	**result;

	result = NULL;
	words_dict = malloc(1024);
	if (!words_dict)
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
				words_dict[i++] = full_dict[j++];
		words_dict[i++] = ' ';
	}
	words_dict[i] = '\0';
	result = ft_split(words_dict, ' ');
	free(words_dict);
	return (result);
}

void	ft_parse(int fd, char *nb)
{
	char	*full_dict;
	char	**numbers_dict;
	char	**words_dict;

	full_dict = ft_parse_dict(fd);
	numbers_dict = ft_parse_numbers(full_dict);
	words_dict = ft_parse_words(full_dict);
	free(full_dict);
	alg_base(numbers_dict, words_dict, nb);
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