/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:55:28 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 10:06:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_line_reader.h"

char	*ft_strcat(char *str, char c, int size)
{
	int		i;
	char	*new;

	new = malloc(size + 2);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = c;
	new[i] = 0;
	free(str);
	return (new);
}

int		add_line(t_line **line, char *data, int size)
{
	t_line	*new;
	t_line	*temp;

	if (!(new = malloc(sizeof(t_line))))
		return (0);
	new->next = NULL;
	new->line = data;
	new->size = size;
	temp = *line;
	if (!temp)
		*line = new;
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = new;
			break ;
		}
		temp = temp->next;
	}
	return (1);
}

void	free_file(t_line **first)
{
	t_line *file;
	t_line *next;

	file = *first;
	while (file)
	{
		next = file->next;
		if (file->line)
			free(file->line);
		free(file);
		file = next;
	}
	*first = NULL;
}

int		free_ret(char *buf, t_line **first)
{
	if (buf)
		free(buf);
	if (first)
		free_file(first);
	return (0);
}

/*
** Loads a file and creates a chained list of lines
** This is a mess... But too lazy to create another
** file for the 5 functions norm...........
*/

int		load_file(char *path, t_line **first, int size)
{
	int		file;
	char	*buf;
	int		read_bytes;
	char	c;

	read_bytes = 0;
	buf = malloc(1);
	if ((file = open(path, O_RDONLY)) == -1 || !buf)
		return (free_ret(buf, NULL));
	buf[0] = 0;
	while ((read_bytes = read(file, &c, 1)) != 0)
		if (read_bytes == -1 || c == 0)
			return (0);
		else if (c == '\n')
		{
			if (!add_line(first, buf, size) || !(buf = malloc(1)))
				return (free_ret(buf, first));
			buf[0] = 0;
			size = 0;
		}
		else
			buf = ft_strcat(buf, c, size++);
	if (size > 0)
		return (add_line(first, buf, size) || free_ret(buf, first));
	return (free_ret(buf, NULL) == 0);
}
