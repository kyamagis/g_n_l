/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:04:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/14 16:27:52 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define FD_CB_NUM 5
# define BUFFER_SIZE 10

typedef struct t_data_buff
{
	char	*saved;
	char	*prefix;
	char	*buff;
	int		readsz;
	int		newl_flag;
	int		null_flg;
}	t_data_buff;

typedef struct t_fd_cb
{
	int			flg;
	int			fd;
	t_data_buff	*pt;
}	t_fd_cb;

char		*get_next_line(int fd);
void	*ft_join_to_nl(t_data_buff *outp_line);
int			ft_strchr_idx(char *s, int c);
char		*ft_strdup(char *s1);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(char *s);
#endif
/*
typedef struct t_data_buff
{
	char	*joined;
	int		nul_flag;
	int		readsz;
	char	*buff;
}	t_data_buff;

outp_line->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // 同じ意味？
	if (outp_line->buff == NULL)
		return (NULL);
*/