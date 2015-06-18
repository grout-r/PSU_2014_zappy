#ifndef MAP
# define MAP

# include <SFML/Graphics.hpp>
# include <vector>
# include <map>
# include <iostream>
# include "Event.hh"
# include "Player.hh"
# include "Case.hh"
# include "Definition.hh"

class							Map
{
private:
  std::vector<Player*>					players;
  std::vector<Case*>					_cases;
  std::pair<int, int>					_size;
  
public:
  Map(std::pair<int, int>);
  ~Map();
  std::pair<int, int>					getSize();

public:
  sf::Sprite*						getPlayerSprite(size_t i);
  Player*						getPlayerFromId(int pid);

public:
  void							movePlayer(int pid, 
								   std::pair<int ,int> pos,
								   e_orientation orientation);
  void							addPlayer(int pid,
								  std::pair<int, int>pos,
								  t_orientation orientation,
								  int level,
								  std::string teamName);
  void							resizeMap(std::pair<int ,int>);
  void							updateCase(std::pair<int, int>,
								   std::map<t_ressource, int>);
};

#endif
