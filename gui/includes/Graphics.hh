
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
  sf::View						_view;
  sf::Image						_grassImage;
  std::map<t_ressource, sf::Image>			_ressourcesImage;
  std::map<t_ressource, sf::Vector2f>			_ressourcesPadding;
  std::map<t_eventName, sf::Vector2f>			_bindMove;
private:
  void							cleanMap(Map *map);
  void							printRessources(Map *map);
  void							printEggs(Map *map);
  void							printPlayers(Map *map);
  
  void							printThisRessourceAtPos
  (t_ressource, std::pair<int, int>);
  
public:
  Graphics(std::pair<int, int>);
  ~Graphics();

  void							handleEvent(std::vector<Event> &);
  void							refreshScreen(Map *map);

public:
  void							moveView(t_eventName key);
};

#endif
