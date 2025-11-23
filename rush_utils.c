/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelero- <imelero-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:09:40 by imelero-          #+#    #+#             */
/*   Updated: 2025/10/22 16:24:35 by imelero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	//printf("i = %ld diff = %d\n\n", i, ((unsigned char) s1[i] - (unsigned char) s2[i]));
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

char	*ft_strdup(const char *s)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *) malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return ((char *) str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	ft_free(char **numbers_dict, char **words_dict)
{
	int		i;

	i = 0;
	while (numbers_dict[i])
	{
		free(numbers_dict[i]);
		i++;
	}
	i = 0;
	free(numbers_dict);
	while (words_dict[i])
	{
		free(words_dict[i]);
		i++;
	}
	free(words_dict);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen((char *)s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}