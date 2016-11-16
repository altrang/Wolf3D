/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:15:51 by atrang            #+#    #+#             */
/*   Updated: 2016/05/21 15:03:55 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void     init_map(t_data *data)
{
	data->posX = 5; // position de depart en x
	data->posY = 5; // position de depart en y
	data->dirX = -1; // vecteur directeur
	data->dirY = 0;  // vecteur directeur
	data->planeX = 0; // deuxieme plan de camera
	data->planeY = 0.66;
	data->time = 0; //temps
	data->oldtime = 0; // temps de limage precedente

}

void     init_map2(t_data *data, int x)
{
	data->cameraX = 2 * x / (double)WIDTH - 1; // coordonnee de la camera dans lespace
	data->rayPosX = data->posX; // coordonnee du rayon
	data->rayPosY = data->posY;
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	data->mapX = (int)data->rayPosX; // dans quelle case de la carte on est
	data->mapY = (int)data->rayPosY;
	data->dist2MurX = sqrt(1 + (data->rayDirY * data->rayDirY) / (data->rayDirX * data->rayDirX)); // longueur des rayons de la pos actuelle au prochain x ou y
	data->dist2MurY = sqrt(1 + (data->rayDirX * data->rayDirX) / (data->rayDirY * data->rayDirY)); // distance entre nous et les murs
	data->touche = 0;
	//return (data);
}
void     init_map3(t_data *data)
{
	if (data->rayDirX < 0) ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur vertical le plus proche en fonction de la prochaine etape x
	{
		data->etapeX = -1; // raydirx < 0 = rayon vers la gauche
		data->distMurX = (data->rayPosX - data->mapX) * data->dist2MurX;
	}
	else
	{
		data->etapeX = 1;
		data->distMurX = (data->mapX + 1.0 - data->rayPosX) * data->dist2MurX;
	}
	if (data->rayDirY < 0)
      {
        data->etapeY = -1; //  On recule
        data->distMurY = (data->rayPosY - data->mapY) * data->dist2MurY; //  On calcule la distance entre le joueur et 1e prochain mur horizontal
      }
  else
      {
        data->etapeY = 1; //  On avance
        data->distMurY = (data->mapY + 1.0 - data->rayPosY) * data->dist2MurY; // On calcule la distance entre joueur et 1e prochain mur horizontal
      }
}

void init_map4(t_data *data)
{
	while (data->touche == 0)
      {
        //Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
        if (data->distMurX < data->distMurY)
        {
          data->distMurX += data->dist2MurX;
          data->mapX += data->etapeX;
          data->murVertiouHori = 0;
        }
        else
        {
          data->distMurY += data->dist2MurY;
          data->mapY += data->etapeY;
          data->murVertiouHori = 1; //Mur vertical
        }
        //Verifier si le rayon a detecte un mur
        if (data->tab[data->mapX][data->mapY] > 0)
        	data->touche = 1;
      }
}
void 	init_map5(t_data *data)
{
	if (data->murVertiouHori == 0)
		data->longueurMur = fabs((data->mapX - data->rayPosX + (1 - data->etapeX) / 2) / data->rayDirX);
	else
		data->longueurMur = fabs((data->mapY - data->rayPosY + (1 - data->etapeY) / 2) / data->rayDirY);
	data->hauteurMur = abs((int)(HEIGHT / data->longueurMur));
	data->start = (-data->hauteurMur / 2 + HEIGHT / 2);
	if (data->start < 0)
		data->start = 0;
	data->end = data->hauteurMur / 2 + HEIGHT / 2;
	if (data->end >= HEIGHT)
		data->end = HEIGHT - 1;
}

int         start(t_data *data)
{
	int x;
	if (data->img != NULL)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	x = 0;
	while (x < WIDTH)
	{
		init_map2(data, x);
		init_map3(data);
		init_map4(data);
		init_map5(data);
		draw_test(data, x);
		x++;
	}
	ft_time(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int        key_func(int keycode, void *param)
{
	t_data *data;
	data = param;


  	if (keycode == 53)
    exit(0);
	if (keycode == 125)// reculer
	{
		if (!(data->tab[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)]))
			data->posX -= data->dirX * data->moveSpeed;
		if (!(data->tab[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)]))
			data->posY -= data->dirY * data->moveSpeed;
	}

	printf("1 = %f\n", data->dirX);
	if (keycode == 126)//avancer
	{
		if (!(data->tab[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)]))
			data->posX += data->dirX * data->moveSpeed;
		if (!(data->tab[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)]))
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

int			main(int ac, char **av)
{
	t_data  *data;
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Wolf3d");
  	if (ac < 2 || ac > 2)
    return (0);
	ft_create_tab(av[1], data);
  	init_map(data);
	mlx_loop_hook(data->mlx, &start, data);
	mlx_hook(data->win, 2, 0, &key_func, data);
	mlx_loop(data->mlx);
	return (0);
}
