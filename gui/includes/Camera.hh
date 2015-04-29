//
// Camera.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:30:30 2015 grout_r
// Last update Tue Apr 28 15:39:35 2015 grout_r
//

#ifndef CAMERA
# define CAMERA

# include "Graphics.hh"
# include "Network.cpp"

class				Camera
{
  Graphics			graph;
  Network			net;
  
public:
  Camera();
  ~Camera();
};

#endif
