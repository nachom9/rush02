#include "rush.h"

void	alg_one(char **numbers_dict, char **words_dict, char *nb)
{
	int		i;

	i = 0;
	while (ft_strcmp(numbers_dict[i], nb) != 0)
		i++;
	write(1, words_dict[i], ft_strlen(words_dict[i]));
}

void	alg_two(char **numbers_dict, char **words_dict, char *nb)
{
	int		i;
	char	*nb_zero;

	i = 0;
	nb_zero = ft_strdup(nb);
	nb_zero[1] = '0';
	if (nb[0] == '1')
		alg_one(numbers_dict, words_dict, nb);
	else
	{
		while (ft_strcmp(numbers_dict[i], nb_zero) != 0)
			i++;
		write(1, words_dict[i], ft_strlen(words_dict[i]) + 1);
		if (nb[1] != '0')
		{
			write(1, " ", 1);
			alg_one(numbers_dict, words_dict, &nb[1]);
		}
	}
	free(nb_zero);
}

void	alg_three(char **numbers_dict, char **words_dict, char *nb)
{
	char	*st;

	st = malloc(2);
	if (!st)
		return ;
	st[0] = nb[0];
	st[1] = '\0';
	if (nb[0] != '0')
	{
		alg_one(numbers_dict, words_dict, st);
		write (1, " hundred", 8);
	}
	if (nb[1] != '0')
	{
		write(1, " and ", 5);
		alg_two(numbers_dict, words_dict, &nb[1]);
	}
	else if (nb[2] != '0')
	{
		write (1, " and ", 5);
		alg_one(numbers_dict, words_dict, &nb[2]);
	}
	free(st);
}

void	ft_write_first(char **numbers_dict, char **words_dict, char *nb, int nb_len)
{
	char	*st;
	char	*sd;

	if (nb_len % 3 == 1)
	{
		st = malloc(2);
		if (!st)
			return ;
		st[0] = nb[0];
		st[1] = '\0';
		alg_one(numbers_dict, words_dict, st);
		free(st);
	}
	else if (nb_len % 3 == 2)
	{
		sd = malloc(3);
		if (!sd)
			return ;
		sd[0] = nb[0];
		sd[1] = nb[1];
		sd[2] = '\0';
		alg_two(numbers_dict, words_dict, sd);
		free(sd);
	}
}

int		ft_check_zero(char *str)
{
	int		i;

	i = 3;
	while (i)
	{
		if (str[i] != '0')
			return (1);
		i--;
	}
	return (0);
}

void	ft_write_lion(int *i, char *nb)
{
	if (!ft_check_zero(nb) && (int)(ft_strlen(nb) / 3) != *i)
		*i = -1;
	if (*i == 1)
		write(1, " thousand", 10);
	else if (*i == 2)
		write(1, " million", 9);
	else if (*i == 3)
		write(1, " billion", 9);
	else if (*i == 4)
		write(1, " trillion", 10);
	else if (*i == 5)
		write(1, " quadrillion", 13);
	else if (*i == 6)
		write(1, " quintillion", 13);
	else if (*i == 7)
		write(1, " sextillion", 12);
	else if (*i == 8)
		write(1, " septillion", 12);
	else if (*i == 9)
		write(1, " octillion", 11);
	else if (*i == 10)
		write(1, " nonillion", 11);
	else if (*i == 11)
		write(1, " decillion", 11);
	else if (*i == 12)
		write(1, " undecillion", 13);
	else if (*i == 13)
		write(1, " dodecillion", 13);
}

void	alg_big(char **numbers_dict, char **words_dict, char *nb, int nb_len)
{
	int		i;
	char	*nb_three; //strdup de las posiciones (nb_len - i*3), (nb_len-i*3)+1 (nb_len-i*3)+2

	i = nb_len / 3;
	if (nb_len % 3 != 0)
	{
		ft_write_first(numbers_dict, words_dict, nb, nb_len);
		ft_write_lion(&i, &nb[nb_len - (i + 1) * 3]);
		if (nb[nb_len % 3] != '0')
			write(1, " ", 1);
		i--;
	}
	if (nb_len % 3 == 0)
		i--;
	while (i > 0 /*&& ft_check_zero(&nb[nb_len % 3])*/)
	{
		nb_three = ft_substr(nb, nb_len - (i + 1) * 3, 3);
			if(!nb_three)
				return ;
		alg_three(numbers_dict, words_dict, nb_three);
		ft_write_lion(&i, &nb[nb_len - (i + 1) * 3]);
		if (nb[nb_len % 3 + 1] != '0')
			write(1, " ", 1);
		i--;
		free(nb_three);
	}
	if (i < 0)
		return ;
	alg_three(numbers_dict, words_dict, &nb[nb_len - 3]);
}

void	alg_base(char **numbers_dict, char **words_dict, char *nb)
{
	int		nb_len;

	nb_len = ft_strlen(nb);
	if (nb_len == 1)
		alg_one(numbers_dict, words_dict, nb);
	else if (nb_len == 2)
		alg_two(numbers_dict, words_dict, nb);
	else if (nb_len == 3)
		alg_three(numbers_dict, words_dict, nb);
	else if (nb_len >= 4)
		alg_big(numbers_dict, words_dict, nb, nb_len);
	ft_free(numbers_dict, words_dict);
}