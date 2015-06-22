/*
** graphiX.h for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/includes
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:36:27 2015 Oscar
** Last update Mon Jun 22 10:34:40 2015 Oscar
*/

#ifndef			GRAPHIX_H_
# define		GRAPHIX_H_

# define		GRAPHIX_INTRODUCTION	"GRAPHIC"

typedef enum		e_gfx_command
{
  MSZ = 0,
  BCT,
  TNA,
  PPO,
  PLV,
  PIN,
  SGT,
  SST,
  SUC
}			t_gfx_command;
  
typedef struct		s_graphix
{
  int			fd;
  struct s_graphix	*next;
}			t_graphix;

#endif			/* !GRAPHIX_H_ */
