/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:44:33 by atrang            #+#    #+#             */
/*   Updated: 2016/05/17 16:57:48 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int       ft_pts(char *str)
{
  int i;
  char **s;

  i = 0;
  s = ft_strsplit(str, ' ');
  while (s[i])
    i++;
  return (i);
}

void ft_create_tab(char *str, t_data *data)
{
  int fd;
  char *s;
  int y;
  int 				**tab;

  y = 0;
  if((fd = open(str, O_RDONLY)) <= 0)
    exit(1);
  while (get_next_line(fd, &s) == 1)
  {
    y++;
  }
  tab = ft_memalloc(sizeof(int*) * (y + 1));
  close(fd);
  if (!(fd = open(str, O_RDONLY)))
    exit(1);
  y = 0;
  while (get_next_line(fd, &s) == 1)
  {
    tab[y] = malloc(sizeof(int) * ft_pts(s));
    y++;
  }
  fill_tab(str, tab, data);
}

int **fill_tab(char *str, int **tab, t_data *data)
{
  char *s;
  char **s2;
  int fd;
  int x;
  int y;
  y = 0;
  fd = open(str, O_RDONLY);
  while (get_next_line(fd, &s) == 1)
  {
    x = 0;
    s2 = ft_strsplit(s, ' ');
    while (x < ft_pts(s))
    {
      tab[y][x] = ft_atoi(s2[x]);
      x++;
    }
    y++;
  }
  data->tab = tab;
  return (0);
}
