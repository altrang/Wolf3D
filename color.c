/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:20:24 by atrang            #+#    #+#             */
/*   Updated: 2016/05/18 11:53:40 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf.h"

void			ft_colors_floor(t_data *data, t_point *point)
{
	int		index;

	index = point->x * data->bpp / 8 + (point->y * data->sizeline);
	if (data->murVertiouHori == 1)
	{
		data->data[index] = 134 / 2;
		data->data[index + 1] = 90 / 2;
		data->data[index + 2] = 90 / 2;
	}
	else
	{
		data->data[index] = 134 / 2;
		data->data[index + 1] = 90 / 2;
		data->data[index + 2] = 90 / 2;
	}
}
void			ft_colors_wall(t_data *data, t_point *point)
{
	int		index;

	index = point->x * data->bpp / 8 + (point->y * data->sizeline);
	if (data->murVertiouHori == 1)
	{
		data->data[index] = 200 / 2;
		data->data[index + 1] = 171 / 2;
		data->data[index + 2] = 152 / 2;
	}
	else
	{
		data->data[index] = 200 / 2;
		data->data[index + 1] = 171 / 2;
		data->data[index + 2] = 152 / 2;
	}
}
void			ft_colors_wall2(t_data *data, t_point *point)
{
	int		index;

	index = point->x * data->bpp / 8 + (point->y * data->sizeline);
	if (data->murVertiouHori == 1)
	{
		data->data[index] = 12 / 2;
		data->data[index + 1] = 12 / 2;
		data->data[index + 2] = 12 / 2;
	}
	else
	{
		data->data[index] = 12 / 2;
		data->data[index + 1] = 145 / 2;
		data->data[index + 2] = 200 / 2;
	}
}
void			ft_colors_wall1(t_data *data, t_point *point)
{
	int		index;

	index = point->x * data->bpp / 8 + (point->y * data->sizeline);
	if (data->murVertiouHori == 1)
	{
		data->data[index] = 255 / 2;
		data->data[index + 1] = 255 / 2;
		data->data[index + 2] = 255 / 2;
	}
	else
	{
		data->data[index] = 255;
		data->data[index + 1] = 255;
		data->data[index + 2] = 255;
	}
}
void		ft_colors_sky(t_data *data, t_point *point)
{
	int		index;

	index = point->x * data->bpp / 8 + (point->y * data->sizeline);
	data->data[index] = 239;
	data->data[index + 1] = 220;
	data->data[index + 2] = 98;
}

void        draw_test(t_data *data, int x)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = 0;
	data->data = mlx_get_data_addr(data->img, &data->bpp, &data->sizeline, &data->endian);
	while (point->y < data->start)
	{
		ft_colors_sky(data, point);
		point->y = point->y + 1;
	}
	point->y = data->start;
	while (point->y < data->end)
	{
		if (data->tab[data->mapX][data->mapY] == 2)
			{
				ft_colors_wall1(data, point);
				point->y = point->y + 1;
			}
		else if (data->tab[data->mapX][data->mapY] == 3)
			{
				ft_colors_wall2(data, point);
				point->y = point->y + 1;
			}
		else
		{
			ft_colors_wall(data, point);
			point->y = point->y + 1;
		}
	}
	point->y = data->end;
	while (point->y < HEIGHT)
	{
		ft_colors_floor(data, point);
		point->y = point->y + 1;
	}
}
