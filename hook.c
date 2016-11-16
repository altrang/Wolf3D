/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 18:18:49 by atrang            #+#    #+#             */
/*   Updated: 2016/05/17 14:28:54 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*int        key_func(int keycode, void *param)
{
	t_data *data;
	data = param;

  printf("x = %F y = %F\n", data->posX, data->posY);
  if (keycode == 53)
    exit(0);
	if (keycode == 125)// reculer
	{
		if (!(lol[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)]))
			data->posX -= data->dirX * data->moveSpeed;
		if (!(lol[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)]))
			data->posY -= data->dirY * data->moveSpeed;
	}

	if (keycode == 126)//avancer
	{
		if (!(lol[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)]))
			data->posX += data->dirX * data->moveSpeed;
		if (!(lol[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)]))
			data->posY += data->dirY * data->moveSpeed;
	}
	if (keycode == 124)//droite
	{
		data->oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = data->oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		data->oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = data->oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (keycode == 123)//gauche
	{
		data->oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = data->oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		data->oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = data->oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	return (0);
}
*/
