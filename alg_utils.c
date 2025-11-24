#include "rush.h"

void	ft_write_first(char **nb_d, char **wd_d, char *nb, int nl)
{
	char	*st;
	char	*sd;

	if (nl % 3 == 1)
	{
		st = malloc(2);
		if (!st)
			return ;
		st[0] = nb[0];
		st[1] = '\0';
		alg_one(nb_d, wd_d, st);
		free(st);
	}
	else if (nl % 3 == 2)
	{
		sd = malloc(3);
		if (!sd)
			return ;
		sd[0] = nb[0];
		sd[1] = nb[1];
		sd[2] = '\0';
		alg_two(nb_d, wd_d, sd);
		free(sd);
	}
}

int	ft_check_zero(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_zero_mod(char *str, int nl)
{
	int		i;

	i = 0;
	while (i < nl)
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_write_lion(int i, char *c)
{
	if (i == 1 && ft_check_zero(c))
		write(1, " thousand", 10);
	else if (i == 2 && ft_check_zero(c))
		write(1, " million", 9);
	else if (i == 3 && ft_check_zero(c))
		write(1, " billion", 9);
	else if (i == 4 && ft_check_zero(c))
		write(1, " trillion", 10);
	else if (i == 5 && ft_check_zero(c))
		write(1, " quadrillion", 13);
	else if (i == 6 && ft_check_zero(c))
		write(1, " quintillion", 13);
	else if (i == 7 && ft_check_zero(c))
		write(1, " sextillion", 12);
	else if (i == 8 && ft_check_zero(c))
		write(1, " septillion", 12);
	else if (i == 9 && ft_check_zero(c))
		write(1, " octillion", 11);
	else if (i == 10 && ft_check_zero(c))
		write(1, " nonillion", 11);
	else if (i == 11 && ft_check_zero(c))
		write(1, " decillion", 11);
	else if (i == 12 && ft_check_zero(c))
		write(1, " undecillion", 13);
}
