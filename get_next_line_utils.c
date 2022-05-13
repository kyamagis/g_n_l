/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:47:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/13 21:00:39 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_to_nl(char const *s1, char const *s2) //const でなければならない？
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == NULL)
		lens1 = 
	lens1 = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && s2[i] != '\n')
		i++;
	if (s2[i] == '\n')
		i++;
	lens2 = i;
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcpy(&str[lens1], s2, lens2 + 1);
	free(s1);
	s1 == NULL;
	free(s2);
	s2 == NULL;
	return (str);
}

int	ft_strchr_idx(const char *s, int c)
{
	size_t			i;
	unsigned char	*suc;
	unsigned char	cuc;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (suc[i] != '\0')
	{
		if (suc[i] == cuc)
			return (i);
		i++;
	}
	if (cuc == '\0')
		return (i);
	return (0);
}

char	*ft_strdup(const char *s1)
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	substr = (char *)malloc (sizeof (char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}