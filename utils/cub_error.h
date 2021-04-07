/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:41:41 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/30 14:12:03 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H

# include "../cub.h"
# include "cub_cleaner.h"

void	handle_error(t_vars *vars, char *error, char *trace);
void	handle_warning(t_vars *vars, char *error);

#endif
