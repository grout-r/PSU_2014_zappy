//
// main.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Mon Apr 27 11:21:41 2015 grout_r
// Last update Thu Jun 25 11:08:21 2015 grout_r
//

#include "Camera.hh"

int				main(int ac, char **av)
{
  Camera			cam(ac, av);

  cam.loop();
  return (0);
}
