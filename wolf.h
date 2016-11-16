/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:37:58 by atrang            #+#    #+#             */
/*   Updated: 2016/05/18 12:04:54 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
#define WOLF_H
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#define WIDTH 500
#include "libft/libft.h"
#define HEIGHT 500
#define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);
/*
const int lol[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
*/
//int **lol;
//const int lol[24][24] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 //				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};

typedef struct 		s_data
{
	void *mlx;
	void *win;
	int    start;
	int    end;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayPosX;
	double rayPosY;
	double rayDirX;
	double rayDirY;
	int	   mapX;
	int    mapY;
	double distMurX;
	double distMurY;
	double dist2MurX;
	double dist2MurY;
	double longueurMur;
	int etapeX;
	int etapeY;
	int touche;
	int murVertiouHori;
	double hauteurMur;
	void *img;
	int bpp;
	int bpp_div;
	int sizeline;
	char *data;
	int endian;
	double time;
	double oldtime;
	double moveSpeed;
	double rotSpeed;
	double frameTime;
	double oldDirX;
	double oldPlaneX;
	int **tab;
}					t_data;



typedef struct     s_point
{
	int x;
	int y;
}					t_point;
void				ft_colors_floor(t_data *data, t_point *point);
void        ft_time(t_data *data);
int         start(t_data *data);
void 				init_map(t_data *data);
void 				init_map2(t_data *data, int x);
void 				init_map3(t_data *data);
void				ft_colors_wall(t_data *data, t_point *point);
void				ft_colors_sky(t_data *data, t_point *point);
void 				init_map4(t_data *data);
void 				init_map5(t_data *data);
void        draw_test(t_data *data, int x);
int       	ft_pts(char *str);
void   			ft_create_tab(char *str, t_data *data);
int 				**fill_tab(char *str, int **tab, t_data *data);
void			ft_colors_wall1(t_data *data, t_point *point);
int			key_funct1(int keycode, void *param);

#endif
