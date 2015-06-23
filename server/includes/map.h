/*
** map.h for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/includes
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 18 17:09:54 2015 Oscar Morizet
** Last update Tue Jun 23 11:27:42 2015 Oscar
*/

#ifndef			MAP_HH_
# define		MAP_HH_

# include		"object.h"

# define		MIN_MAP_SIZE	3

typedef struct		s_map_case
{
  t_object		obj;
  struct s_map_case	*next;
}			t_map_case;

int			add_map_case_element(t_map_case **list, t_object obj);
void			remove_map_case_element(t_map_case **list, t_object obj);

#endif			/* !MAP_HH_ */
