/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:55:24 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:18:11 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CHECKER_H
# define CUB_CHECKER_H

# include "../cub.h"
# include "cub_error.h"

void	check_textures_custom(t_vars *vars);
void	check_textures(t_vars *vars);
void	check_define(t_vars *vars);

#endif
