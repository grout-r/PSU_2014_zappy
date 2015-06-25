#ifndef MAP
# define MAP

# include <SFML/Graphics.hpp>
# include <vector>
# include <map>
# include <iostream>
# include <algorithm>
# include "Event.hh"
# include "Player.hh"
# include "Case.hh"
# include "Definition.hh"
# include "Egg.hh"

class							Map
{
private:
  std::vector<Player*>					players;
  std::vector<Egg*>					_eggs;
  std::vector<Case*>					_cases;
  std::pair<int, int>					_size;
  std::pair<int, int>					_hudLookAt;

public:
  Map(std::pair<int, int>);
  ~Map();
  std::pair<int, int>					getSize();

public:
  void							setHud(std::pair<int, int>);
  std::pair<int, int>					getHud();
  Egg*							getEgg(size_t i);
  sf::Sprite*						getPlayerSprite(size_t i);
  Case*							getCase(size_t i);
  Case*							getCaseFromPos(std::pair<int, int>);
  Player*						getPlayerFromId(int pid);
  Player*						getPlayerFromPos(std::pair<int, int>);
public:
  void							updateInventory
  (int pid, std::map<t_ressource, int>);
  void							pexPlayer(int pid, int level);
  void							movePlayer(int pid, 
								   std::pair<int ,int> pos,
								   e_orientation orientation);
  void							addPlayer(int pid,
								  std::pair<int, int>pos,
								  t_orientation orientation,
								  int level,
								  std::string teamName);
  void							addEgg(int egId, int pid, 
							       std::pair<int, int> pos);
  void							resizeMap(std::pair<int ,int>);
  void							updateCase(std::pair<int, int>,
								   std::map<t_ressource, int>);
};

#endif
