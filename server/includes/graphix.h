/*
** graphiX.h for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/includes
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:36:27 2015 Oscar
** Last update Tue Jun 23 15:12:57 2015 Oscar
*/

#ifndef			GRAPHIX_H_
# define		GRAPHIX_H_

# define		GRAPHIX_INTRODUCTION	"GRAPHIC"

typedef enum		e_gfx_command
{
  MSZ = 0,
  BCT,
  MCT,
  TNA,
  PPO,
  PLV,
  PIN,
  SGT,
  SUC
}			t_gfx_command;

typedef struct		s_graphix
{
  int			fd;
  struct s_graphix	*next;
}			t_graphix;

#endif			/* !GRAPHIX_H_ */
