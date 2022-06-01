/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:04:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/01 14:47:40 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_MAX 256
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_free_str(char	*buff, char *saved_str);
char	*ft_strdup(char *s1);
#endif
