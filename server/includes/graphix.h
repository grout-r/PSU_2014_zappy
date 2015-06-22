/*
** graphiX.h for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/includes
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:36:27 2015 Oscar
** Last update Mon Jun 22 08:35:33 2015 Oscar
*/

#ifndef			GRAPHIX_H_
# define		GRAPHIX_H_

# define		GRAPHIX_INTRODUCTION	"GRAPHIC"

typedef enum		e_gfx_command
{
  MSZ = 0,
  BCT,
  TNA,
  PNW,
  PPO,
  PLV,
  PIN,
  PEX,
  PBC,
  PIC,
  PIE,
  PFK,
  PDR,
  PGT,
  PDI,
  ENW,
  EHT,
  EBO,
  EDI,
  SGT,
  SEG,
  SMG,
  SUC,
  SBP
}			t_gfx_command;
  
typedef struct		s_graphix
{
  int			fd;
  struct s_graphix	*next;
}			t_graphix;

#endif			/* !GRAPHIX_H_ */
