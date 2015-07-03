#ifndef CASE
#define CASE

# include <SFML/Graphics.hpp>
# include <utility>
# include <map>
# include <iostream>
# include "Definition.hh"

class					Case
{
private:
  std::pair<int, int>			_pos;
  std::map<t_ressource, int>		_ressources;
  sf::Clock				_timer;
  t_incant				_status;

public:
  Case(std::pair<int, int>);
  ~Case();
  std::pair<int, int>			getPos();
  void					setRessources(std::map<t_ressource, int>);
  std::map<t_ressource, int>		getRessources();
 
public:
  int					askInventory(t_ressource);
  void					startIncant();
  void					resultIncant(bool res);
  t_incant				getStatus();
  void					update();
};

#endif
