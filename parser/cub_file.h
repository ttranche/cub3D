/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:12:48 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:05:32 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FILE_H
# define CUB_FILE_H

# include "../utils/cub_error.h"
# include "cub_parser.h"
# include "cub_map_parser.h"
# include "../cub.h"

int	load_f(char *filepath, t_vars *vars);

#endif
