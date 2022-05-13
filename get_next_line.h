/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:04:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/13 21:03:38 by kyamagis         ###   ########.fr       */
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
# define BUFFER_SIZE     10      // todo デバッグ用。デバッグ終了時に、本行を消すこと

typedef struct data_buff_t 
{
	char	*joined;
	int		nul_flag;
	int		readsz;
	char	*buff;
} data_buff_t;

// fd制御ブロック
typedef struct fd_cb_t 
{
	int			flg;        // 0=empty, 1=use
	int			fd;
	data_buff_t	*pt;
} fd_cb_t;

char	*get_next_line(int fd);
char	*ft_join_to_nl(char const *s1, char const *s2);
int		ft_strchr_idx(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
#endif

/*

*/