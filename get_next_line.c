/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:45:21 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/14 16:31:28 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data_buff	*ft_free_str(t_data_buff	*outp_line, int	flag)
{
	if (flag == 1)
	{
		free(outp_line->prefix);
		outp_line->prefix = NULL;
	}
	free(outp_line->saved);
	outp_line->saved = NULL;
	free(outp_line->buff);
	outp_line->buff = NULL;
	return (NULL);
}

t_data_buff	*read_file(int	fd, char *saved_str, t_data_buff *outp_line)
{
	outp_line->prefix = saved_str;
	outp_line->readsz = 1;
	while (0 < outp_line->readsz)
	{
		outp_line->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // いるのか？
		if (outp_line->buff == NULL)
			return (NULL);
		outp_line->readsz = read(fd, outp_line->buff, BUFFER_SIZE);
		if (outp_line->readsz == -1)
			return (ft_free_str(outp_line, 1));
		while (outp_line->readsz++ <= BUFFER_SIZE) //ft_memset(&buff[readsz], '\0', BUFFER_SIZE - readsz + 1);
			outp_line->buff[outp_line->readsz] = '\0';
		ft_join_to_nl(outp_line);
		if (outp_line->prefix == NULL || outp_line->null_flg == 1)
			return (ft_free_str(outp_line, 1));
		if (outp_line->newl_flag == 1)
			break;
	}
	return (outp_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_str; // 初期値はNULL;
	t_data_buff	*outp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	outp_line = (t_data_buff *)malloc(sizeof(t_data_buff));// 変数が一つでもallocできなくてもNULLを返すのか？
	if (outp_line == NULL)
		return (NULL);
	if (saved_str == NULL)
	{
		outp_line->prefix = ft_strdup("");
		if (outp_line->prefix == NULL)
			return (NULL);
	}	
	outp_line = read_file(fd, saved_str, outp_line);
	if (outp_line == NULL)
		return (NULL);
	saved_str = outp_line->saved;
	ft_free_str(outp_line, 0);
	return (outp_line->prefix);
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

	//t_data_buff	*test;
	static char		*cutstr;

	printf("%s", cutstr);
	

}
