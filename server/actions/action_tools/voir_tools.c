/*
** voir_tools.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions/action_tools
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue May 26 13:56:54 2015 Oscar Morizet
** Last update Tue May 26 14:52:36 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

void		trace_move(t_coords *coords, t_orientation orientation)
{
  if (orientation == LEFT)
    --coords->x;
  else if (orientation == UP)
    --coords->y;
  else if (orientation == RIGHT)
    ++coords->x;
  else
    ++coords->y;
}

void		move_perpendicular(t_coords *coords, t_orientation orientation)
{
  if (orientation == LEFT)
    --coords->y;
  else if (orientation == UP)
    ++coords->x ;
  else if (orientation == RIGHT)
    ++coords->y;
  else
    --coords->x;
}

void		get_perpendicular_begin(t_coords *coords, int index,
					t_orientation orientation)
{
  if (orientation == LEFT)
    coords->y += index;
  else if (orientation == UP)
    coords->x -= index;
  else if (orientation == RIGHT)
    coords->y -= index;
  else
    coords->x += index;
}

void		make_round(t_coords *coords, int xmax, int ymax)
{
  if (coords->x < 0)
    coords->x += xmax;
  if (coords->x >= xmax)
    coords->x -= xmax;
  if (coords->y < 0)
    coords->y += ymax;
  if (coords->y >= ymax)
    coords->y -= ymax;
}
