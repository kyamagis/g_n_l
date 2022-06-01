/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:45:21 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/01 14:47:31 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*dup_nl_to_null(char *saved_str)
{
	size_t		nl_point;
	char		*tmp_str;

	nl_point = 0;
	while (saved_str[nl_point] != '\0' && saved_str[nl_point] != '\n')
		nl_point++;
	if (saved_str[nl_point] == '\n')
		nl_point++;
	tmp_str = ft_strdup(&saved_str[nl_point]);
	ft_free_str(NULL, saved_str);
	if (tmp_str == NULL)
		return (NULL);
	saved_str = tmp_str;
	return (saved_str);
}

static char	*dup_to_nl(char *saved_str)
{
	char	*output_line;
	size_t	nl_point;

	nl_point = 0;
	while (saved_str[nl_point] != '\0' && saved_str[nl_point] != '\n')
		nl_point++;
	if (saved_str[nl_point] == '\n')
		nl_point++;
	output_line = (char *)malloc (sizeof(char) * (nl_point + 1));
	if (output_line == NULL)
		return (NULL);
	ft_strlcpy(output_line, saved_str, nl_point + 1);
	return (output_line);
}

static char	*ft_join_to_null(char	*saved_str, char *buff)
{
	char	*joined;
	size_t	len_sv;
	size_t	len_bf;

	len_sv = ft_strlen(saved_str);
	len_bf = ft_strlen(buff);
	joined = (char *)malloc(sizeof(char) * (len_sv + len_bf + 1));
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, saved_str, len_sv + 1);
	ft_strlcpy(&joined[len_sv], buff, len_bf + 1);
	return (joined);
}

static char	*read_to_null(int fd, char *saved_str)
{
	ssize_t	readsz;
	char	*buff;
	char	*tmp_str;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	readsz = 1;
	while (0 < readsz && ft_strchr(saved_str, '\n') == NULL)
	{
		readsz = read(fd, buff, BUFFER_SIZE);
		if (readsz == -1 || (readsz == 0 && saved_str[0] == '\0'))
			return (ft_free_str(buff, saved_str));
		buff[readsz] = '\0';
		tmp_str = ft_join_to_null(saved_str, buff);
		if (tmp_str == NULL)
			return (ft_free_str(buff, saved_str));
		ft_free_str(NULL, saved_str);
		saved_str = tmp_str;
	}
	ft_free_str(buff, NULL);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	static char	*saved_str[FD_MAX];
	char		*output_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX <= fd)
		return (NULL);
	if (saved_str[fd] == NULL)
	{
		saved_str[fd] = ft_strdup("");
		if (saved_str[fd] == NULL)
			return (NULL);
	}
	saved_str[fd] = read_to_null(fd, saved_str[fd]);
	if (saved_str[fd] == NULL)
		return (NULL);
	output_line = dup_to_nl(saved_str[fd]);
	if (output_line == NULL)
		return (ft_free_str(NULL, saved_str[fd]));
	saved_str[fd] = dup_nl_to_null(saved_str[fd]);
	if (saved_str[fd] == NULL)
		return (ft_free_str(output_line, NULL));
	return (output_line);
}

/*int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*lineBf;
	char	*lineBf1;
	char	*lineBf2;

	fd = open("test.txt", O_RDONLY , 0);
	fd1 = open("test1.txt", O_RDONLY , 0);
	fd2 = open("test2.txt", O_RDONLY , 0);
	if (fd < 0)
	{
		printf("!!! ERROR 1 !!!\n");
	}
	while (1)
	{
		lineBf = get_next_line(fd);
		lineBf1 = get_next_line(fd1);
		lineBf2 = get_next_line(fd2);
		
		if (lineBf == NULL || lineBf1 == NULL || lineBf2 == NULL)
		{
			printf("EOF\n");
			break;
		}
		printf("%s", lineBf);
		printf("%s", lineBf1);
		printf("%s", lineBf2);
	}

	printf("+++++++++++++++++++++++++++++++++++++++++\n");
}*/
