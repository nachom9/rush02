#include "rush.h"

void	alg_one(char **nb_d, char **wd_d, char *nb)
{
	int		i;

	i = 0;
	while (ft_strcmp(nb_d[i], nb) != 0)
		i++;
	write(1, wd_d[i], ft_strlen(wd_d[i]));
}

void	alg_two(char **nb_d, char **wd_d, char *nb)
{
	int		i;
	char	*nb_zero;

	i = 0;
	nb_zero = ft_strdup(nb);
	nb_zero[1] = '0';
	if (nb[0] == '1')
		alg_one(nb_d, wd_d, nb);
	else
	{
		while (ft_strcmp(nb_d[i], nb_zero) != 0)
			i++;
		write(1, wd_d[i], ft_strlen(wd_d[i]) + 1);
		if (nb[1] != '0' && nb[0])
		{
			write(1, " ", 1);
			alg_one(nb_d, wd_d, &nb[1]);
		}
	}
	free(nb_zero);
}

static void	alg_three(char **nb_d, char **wd_d, char *nb)
{
	char	*st;

	st = malloc(2);
	if (!st)
		return ;
	st[0] = nb[0];
	st[1] = '\0';
	if (nb[0] != '0')
	{
		alg_one(nb_d, wd_d, st);
		write (1, " hundred", 8);
		if (nb[1] != '0' || nb[2] != '0')
			write(1, " ", 1);
	}
	if (nb[1] != '0')
		alg_two(nb_d, wd_d, &nb[1]);
	else if (nb[2] != '0')
		alg_one(nb_d, wd_d, &nb[2]);
	free(st);
}

static void	alg_big(char **nb_d, char **wd_d, char *nb, int nl)
{
	char	*nb_three;
	char	*s;

	s = nb;
	if (nl % 3 != 0)
	{
		ft_write_first(nb_d, wd_d, nb, nl);
		ft_write_lion(nl / 3, nb);
		if (ft_check_zero_mod(&nb[(nl % 3) - 2], nl) && ft_check_zero(&s[1]))
			write(1, " ", 1);
		nb += nl % 3;
		nl -= nl % 3;
	}
	while (nl > 3 && ft_check_zero(nb))
	{
		nb_three = ft_substr(nb, 0, 3);
		alg_three(nb_d, wd_d, nb_three);
		ft_write_lion((nl - 3) / 3, nb_three);
		if (ft_check_zero_mod(&nb[0], 3) && ft_check_zero(&nb[3]))
			write(1, " ", 1);
		nb += 3;
		nl = ft_strlen(nb);
		free(nb_three);
	}
	alg_three(nb_d, wd_d, nb);
}

void	alg_base(char **nb_d, char **wd_d, char *nb)
{
	int		nl;

	nl = ft_strlen(nb);
	if (nl == 1)
		alg_one(nb_d, wd_d, nb);
	else if (nl == 2)
		alg_two(nb_d, wd_d, nb);
	else if (nl == 3)
		alg_three(nb_d, wd_d, nb);
	else if (nl >= 4)
		alg_big(nb_d, wd_d, nb, nl);
	ft_free(nb_d, wd_d);
}
