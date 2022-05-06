/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:04:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/06 12:21:13 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define _POSIX_SOURCE
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

#define BUFFER_SIZE     10      // todo デバッグ用。デバッグ終了時に、本行を消すこと

typedef struct Data_Buf_t 
{
	struct Data_Buf_t	*nxt;
	int					sz;
	int					ix;
	char				bf[BUFFER_SIZE];
} Data_Buf_t;

// fd制御ブロック
typedef struct Fd_CB_t 
{
	int			flg;        // 0=empty, 1=use
	int			fd;
	Data_Buf_t	*pt;
} Fd_CB_t;

char		*get_next_line(int fd);
Fd_CB_t		*find_fd_cb(int fd);
Data_Buf_t	*read_file(int fd);
void		clear_fd_cb(Fd_CB_t *fdCB);
char		*copy_data(Fd_CB_t *fdCB, int lineSz);

#endif