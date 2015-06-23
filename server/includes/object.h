/*
** object.h for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/components
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue May 26 15:02:34 2015 Oscar Morizet
** Last update Tue Jun 23 08:51:10 2015 Oscar
*/

#ifndef	        OBJECT_H_
# define        OBJECT_H_

# define	MAX_OBJECTS	8

typedef enum	e_object
  {
    PLAYER = 0,
    NOURRITURE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
  }		t_object;

#endif		/* !OBJECT_H_ */
