/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelero- <imelero-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:54:39 by imelero-          #+#    #+#             */
/*   Updated: 2025/10/13 18:45:31 by imelero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

#include <stdio.h> //ELIMINAR DESPUÉS
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_parse(int fd, char *nb);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_parse_dict(int fd);
char	**ft_split(char const *s, char c);
void	alg_base(char **numbers_dict, char **words_dict, char *nb);
size_t	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **numbers_dict, char **words_dict);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
