
#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SFML/Graphics.hpp>
# include <utility>
# include <vector>
# include <map>
# include <iostream>
# include "Event.hh"
# include "Player.hh"
# include "Map.hh"
# include "Definition.hh"

class							Graphics;

typedef	void						(Graphics::*printRsPtr)
(std::pair<int, int>);

class							Graphics
{
private:
  sf::RenderWindow					*app;
  sf::Image						_grassImage;
  std::map<t_ressource, sf::Image>			_ressourcesImage;
  std::map<t_ressource, sf::Vector2f>			_ressourcesPadding;
  
private:
  void							cleanMap(Map *map);
  void							printRessources(Map *map);
  void							printPlayers(Map *map);
  
  void							printThisRessourceAtPos
  (t_ressource, std::pair<int, int>);
  
public:
  Graphics();
  ~Graphics();

  void							handleEvent();
  void							refreshScreen(Map *map);
};

#endif
