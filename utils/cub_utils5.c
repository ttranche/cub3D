/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:05:08 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:16:03 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

double	ease_in_out(double t)
{
	float sqt;

	sqt = t * t;
	return (sqt / (2.0f * (sqt - t) + 1.0f));
}

void	*make_closedmap(int size)
{
	int		i;
	char	*new;

	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = 0;
	return (new);
}

int		stringlen(char *string)
{
	int len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

void	truncate_str(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	len--;
	while (len >= 0 && s[len] == ' ')
		s[len--] = 0;
}

int		bad_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 0;
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		if (++i >= n)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
