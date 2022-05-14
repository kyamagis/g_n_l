/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:47:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/14 17:11:36 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_to_nl (t_data_buff *outp_line)
{
	size_t len_bf;

	len_bf = 0;
	while (outp_line->buff[len_bf] != '\0' && outp_line->buff[len_bf] != '\n')
		len_bf++;
	if (outp_line->buff[len_bf] == '\n')
	{
		outp_line->newl_flag = 1;
		len_bf++;
		outp_line->saved = ft_strdup(&outp_line->buff[len_bf]);
		if (outp_line->saved == NULL)
			outp_line->null_flg = 1;
	}
	return (len_bf);
}

void	*ft_join_to_nl(t_data_buff *outp_line)
{
	char	*joined;
	size_t	len_pr;
	size_t	len_bf;

	len_pr = ft_strlen(outp_line->prefix);
	len_bf = ft_strlen_to_nl(outp_line);
	if (outp_line->newl_flag == 1)
		return;
	joined = (char *)malloc(sizeof(char) * (len_pr + len_bf + 1));
	if (joined == NULL)
	{
		outp_line->null_flg = 1;
		return;
	}
	ft_strlcpy(joined, outp_line->prefix, len_pr + 1);
	ft_strlcpy(&joined[len_pr], outp_line->buff, len_bf + 1);
	ft_free_str(outp_line);//free(buff);buff == NULL いる？
	outp_line->prefix = joined;
}

char	*ft_strdup(char *s1)
{
	char	*prc;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	prc = (char *)malloc(sizeof(char) * (lens1 + 1));
	if (prc == NULL)
		return (NULL);
	ft_strlcpy(prc, s1, lens1 + 1);
	return (prc);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	char	*castsrc;

	castsrc = (char *) src;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	i = 0;
	while (i < size - 1 && castsrc[i] != '\0')
	{
		dest[i] = castsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	char *str;
	t_data_buff	*outp_1;

	// outp_1->prefix = ;
	// outp_1->buff = ;
	// outp_1->saved = ;
	outp_1 = (t_data_buff *)malloc(sizeof(t_data_buff));

	ft_str_nl (outp_1, 0);
	printf("%d", outp_1->null_flg);
	
	str = (char *)malloc(sizeof(char) * (5));
	str[1] = '1';
	printf("%s", str);
}