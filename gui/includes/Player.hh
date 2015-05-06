//
// Player.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Thu Apr 30 14:15:36 2015 grout_r
// Last update Mon May  4 16:25:03 2015 grout_r
//

#ifndef PLAYER
# define PLAYER

# include <SFML/Graphics.hpp>
# include <utility>
# include <map>

typedef enum					e_orientation
  {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
  }						t_orientation;
  
class						Player
{
private:
  int						pid;
  std::pair<int, int>				pos;
  sf::Image					*skin;
  t_orientation					orientation;
  int						level;
  std::string					teamName;
private:
  std::map<t_orientation, sf::IntRect>		IntRectFromOrientation;
public:
  Player(int pid, std::pair<int, int> pos, t_orientation orientation,
	 int level, std::string teamName);
  ~Player();

  std::pair<int, int>				getPos();
  void						setPos(std::pair<int, int>);
  sf::Image*					getSkin();
  int						getPid();
  void						setOrientation(t_orientation);
  sf::IntRect					getIntRectFromOrientation();
};

#endif
