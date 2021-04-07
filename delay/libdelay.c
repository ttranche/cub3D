/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdelay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:12:18 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 10:09:36 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>

int		get_delay(bool startnow, int min, bool mac)
{
	static struct timeval	start;
	static struct timeval	stop;
	unsigned long			delta_us;

	if (startnow)
	{
		gettimeofday(&start, NULL);
		return (0);
	}
	else
		gettimeofday(&stop, NULL);
	delta_us = (stop.tv_sec - start.tv_sec) * 1000000
		+ stop.tv_usec - start.tv_usec;
	if (delta_us < (unsigned long)min)
	{
		if (!mac)
			usleep((min - delta_us) % 1000000);
		return (0);
	}
	return (delta_us - min);
}
