/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:45:21 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/13 21:04:53 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_str(data_buff_t	*outp_line)
{
	free(outp_line->buff);
	outp_line->buff = NULL;
	free(outp_line->joined);
	outp_line->joined = NULL;
	return (NULL);
}

data_buff_t	*read_file(int	fd, char *saved_str)
{
	size_t		i;
	data_buff_t	*outp_line;	// outp_line自体を malloc しなくていいのか

	outp_line = (data_buff_t *)malloc(sizeof(data_buff_t));
	if (outp_line == NULL)
		return (NULL);
	outp_line->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // いるのか？
	if (outp_line->buff == NULL)
		return (NULL);
	outp_line->joined = saved_str;
	i = 0;
	outp_line->readsz = 1;
	while (ft_strchr_idx(outp_line->buff, '\n') == 0 && 0 < outp_line->readsz)
	{
		outp_line->readsz = read(fd, outp_line->buff, BUFFER_SIZE);
		if (outp_line->readsz == -1)
			return (ft_free_str(outp_line));
		while (outp_line->readsz++ <= BUFFER_SIZE) //ft_memset(&buff[readsz], '\0', BUFFER_SIZE - readsz + 1);
			outp_line->buff[outp_line->readsz] = '\0';
		outp_line->joined = ft_join_to_nl(outp_line->joined, outp_line->buff);
		if (outp_line->joined == NULL)
			return (ft_free_str(outp_line));
		outp_line->buff = saved_str;
		i++;
	}
	return (outp_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_str; // 初期値はNULL;
	data_buff_t	*outp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	outp_line = read_file(fd, saved_str);
	if (outp_line == NULL)
		return (NULL);

	
	saved_str = outp_line->buff;
	return (outp_line->joined);
}

int	main(void)
{
	// int		fd;
	// char	*lineBf;

	// fd = open("test.txt", O_RDONLY | O_BINARY, 0);
	// if (fd < 0)
	// {
	// 	printf("!!! ERROR 1 !!!\n");
	// 	exit(1);
	// }
	// while (1)
	// {
	// 	lineBf = get_next_line(fd);
	// 	if (lineBf == NULL)
	// 	{
	// 		printf("EOF\n");
	// 		break;
	// 	}
	// 	printf("%s", lineBf);
	// }
	// exit(0);

	//data_buff_t	*test;
	static char		*cutstr;

	printf("%s", cutstr);
	

}
