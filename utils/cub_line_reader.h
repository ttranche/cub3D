/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_reader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:34:25 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 10:02:56 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LINE_READER_H
# define CUB_LINE_READER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}					t_line;

char				*ft_strcat(char *str, char c, int size);
int					load_file(char *path, t_line **first, int size);
void				free_file(t_line **first);
int					add_line(t_line **line, char *data, int size);
int					free_ret(char *buf, t_line **first);

#endif
