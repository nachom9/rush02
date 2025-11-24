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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

void	ft_parse(int fd, char *nb);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_parse_dict(int fd);
char	**ft_split(char const *s, char c);
void	alg_base(char **nb_d, char **wd_d, char *nb);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **nb_d, char **wd_d);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_write_first(char **nb_d, char **wd_d, char *nb, int nl);
int		ft_check_zero(char *str);
int		ft_check_zero_mod(char *str, int nl);
void	ft_write_lion(int i, char *c);
void	alg_one(char **nb_d, char **wd_d, char *nb);
void	alg_two(char **nb_d, char **wd_d, char *nb);

#endif
