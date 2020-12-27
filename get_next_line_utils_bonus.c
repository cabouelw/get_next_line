/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:55:52 by cabouelw          #+#    #+#             */
/*   Updated: 2020/01/02 15:55:57 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if ((!dst || !src))
		return (0);
	s = (unsigned char*)src;
	d = dst;
	while (n--)
		*(d++) = *(s++);
	return (dst);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_substr(char const *src, unsigned int start, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	if (!src)
		return (ft_strjoin("", ""));
	len = ft_strlen(src + start);
	if (n > len)
		n = len;
	if ((dst = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	ft_memcpy(dst, src + start, n);
	dst[n] = '\0';
	return (dst);
}

char		*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(p = (char*)malloc(len1 + len2 + 1)))
		return (NULL);
	ft_memcpy(p, s1, len1);
	ft_memcpy(p + len1, s2, len2 + 1);
	return (p);
}
