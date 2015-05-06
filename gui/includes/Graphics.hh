//
// Graphics.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:46:12 2015 grout_r
// Last update Tue May  5 14:09:08 2015 grout_r
//

#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SFML/Graphics.hpp>
# include <vector>
# include <iostream>
# include "Event.hh"
# include "Player.hh"

class							Graphics
{
private:
  sf::Image						grass;
  sf::RenderWindow					*app;
  std::vector<std::vector<sf::Sprite*> >		map;
  std::vector<Player*>					players;
private:
  void							resetMap();
  void							printGrass(sf::Sprite *currentCase);
  void							printPlayer(Player *tmpPlayer);
  Player*						getPlayerFromId(int pid);
public:
  Graphics();
  ~Graphics();
  void							handleEvent();
  void							refreshScreen();
  void							movePlayer(int pid, 
								   std::pair<int ,int> pos,
								   e_orientation orientation);
  void							addPlayer(int pid,
								  std::pair<int, int>pos,
								  t_orientation orientation,
								  int level,
								  std::string teamName);
};

#endif
