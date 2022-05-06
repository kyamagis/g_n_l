/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:45:21 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/06 12:13:06 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	Fd_CB_t		*fdCB;
	char		c;
	size_t		lineSz;
	Data_Buf_t	*currPt;
	int			currIx;
	char		*lineBf;

	fdCB = find_fd_cb(fd);
	if (fdCB == NULL)       // FD制御ブロックの空き無し
		return (NULL);
	if (fdCB->pt == NULL)
	{
		fdCB->pt = read_file(fd);
		if (fdCB->pt == NULL)       // 読みだすデータが無いか、またはメモリがない
		{
			clear_fd_cb(fdCB);      // fdCBをクリアする
			return (NULL);
		}
	}
	lineSz = 0;
	currPt = fdCB->pt;
	currIx = currPt->ix;
	while(1)
	{
		c = currPt->bf[currIx];
		++lineSz;
		++currIx;
		if (c == '\n')
		{
			lineBf = copy_data(fdCB, lineSz);
			if (lineBf == NULL)
				clear_fd_cb(fdCB);      // fdCBをクリアする
			return (lineBf);
		}
		if (currIx >= currPt->sz)
		{
			if (currPt->sz < BUFFER_SIZE)   // これ以上読みだすデータが無い場合
			{
				clear_fd_cb(fdCB);      // fdCBをクリアする
				return (NULL);
			}
			currPt->nxt = read_file(fd);
			if (fdCB->pt == NULL)       // 読みだすデータが無いか、またはメモリがない
			{
				clear_fd_cb(fdCB);      // fdCBをクリアする
				return (NULL);
			}
			currIx = 0;
			currPt = currPt->nxt;
		}
	}
}

/*int	main(void)
{
	int		fd;
	char	*lineBf;

	fd = open("test.txt", O_RDONLY | O_BINARY, 0);
	if (fd < 0)
	{
		printf("!!! ERROR 1 !!!\n");
		exit(1);
	}
	while (1)
	{
		lineBf = get_next_line(fd);
		if (lineBf == NULL)
		{
			printf("EOF\n");
			break;
		}
		printf("%s", lineBf);
	}
	exit(0);
}*/
