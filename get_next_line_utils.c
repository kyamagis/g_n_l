/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:47:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/06 18:41:43 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define FD_CB_NUM 5
static Fd_CB_t fdCB[FD_CB_NUM];

// fd制御ブロックを探す
Fd_CB_t *find_fd_cb(int fd)
{
	int	i;
	int	emptyIx;

	emptyIx = -1;
	i = 0;
	while (i < FD_CB_NUM) 
	{
		if (fdCB[i].flg != 0 && fdCB[i].fd == fd)
			return (&fdCB[i]);     // 登録済み
		else
		{
			if (emptyIx == -1)
				emptyIx = i;
		}
		++i;
	}
	if (emptyIx == -1)
		return (NULL);        // 登録できる空きが無い
	fdCB[emptyIx].flg = 1;        // 使用中
	fdCB[emptyIx].fd = fd;
	fdCB[emptyIx].pt = NULL;
	return (&fdCB[emptyIx]);
}


// fdCBをクリアする
void	clear_fd_cb(Fd_CB_t *fdCB)
{
	Data_Buf_t	*currPt;
	Data_Buf_t	*nxtPt;

	currPt = fdCB->pt;
	while (currPt != NULL)        // 確保済みバッファを開放する
	{
		nxtPt = currPt->nxt;
		free(currPt);
		currPt = nxtPt;
	}
	fdCB->flg = 0;              // fdCBをクリアする
}


// BFエリアの獲得とファイルの読出し
Data_Buf_t	*read_file(int fd)
{
	Data_Buf_t	*currPt;

	currPt = (Data_Buf_t *)malloc(sizeof(Data_Buf_t));
	if (currPt == NULL)
		return (NULL);
	currPt->sz = read(fd, currPt->bf, BUFFER_SIZE);
	if (currPt->sz <= 0)
	{
		free(currPt);
		return (NULL);
	}
	currPt->nxt = NULL;
	currPt->ix  = 0;
	return currPt;
}

// バッファを開放しながら1行を作る
// lineSzは1以上
char	*copy_data(Fd_CB_t *fdCB, int lineSz)
{
	char		*lineBf;
	Data_Buf_t	*currPt;
	Data_Buf_t	*emptytPt;
	size_t		distIx;
	int			cpSz;

	lineBf = (char *)malloc(lineSz + 1);
	if (lineBf == NULL)
		return (NULL);
	lineBf[lineSz] = 0;         // 不要な時は消す
	distIx = 0;
	currPt = fdCB->pt;
	while (lineSz != 0)
	{
		cpSz = currPt->sz - currPt->ix;
		if (cpSz > lineSz)
			cpSz = lineSz;
		ft_memcpy(&lineBf[distIx], &currPt->bf[currPt->ix], cpSz);
		lineSz -= cpSz;
		distIx += cpSz;
		currPt->ix += cpSz;
		if (currPt->ix == currPt->sz)
		{
			emptytPt = currPt;
			currPt = currPt->nxt;
			free(emptytPt);
		}
	}
	fdCB->pt = currPt;
	return (lineBf);
}
