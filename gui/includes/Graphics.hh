
#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SFML/Graphics.hpp>
# include <utility>
# include <vector>
# include <iostream>
# include "Event.hh"
# include "Player.hh"
# include "Map.hh"

class							Graphics
{
private:
  sf::RenderWindow					*app;
  sf::Image						_grassImage;

public:
  Graphics();
  ~Graphics();

  void							cleanMap(Map *map);
  void							handleEvent();
  void							refreshScreen(Map *map);
};

#endif
