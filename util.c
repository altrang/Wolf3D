/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:59:31 by atrang            #+#    #+#             */
/*   Updated: 2016/05/19 11:48:00 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void           ft_time(t_data *data)
{
	struct timeval time;

	data->oldtime = data->time;
	gettimeofday(&time, NULL);
	data->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	data->frameTime = (data->time - data->oldtime);
	data->moveSpeed = data->frameTime * 0.003 * 2;
	data->rotSpeed = data->frameTime * 0.005;

}
