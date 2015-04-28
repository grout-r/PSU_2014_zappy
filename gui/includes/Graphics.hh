//
// Graphics.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:46:12 2015 grout_r
// Last update Tue Apr 28 15:24:12 2015 grout_r
//

#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SFML/Graphics.hpp>
# include "Event.hh"

class					Graphics
{
private:
  sf::RenderWindow			*app;
public:
  Graphics();
  ~Graphics();
  Event					getEvent();
};

#endif
