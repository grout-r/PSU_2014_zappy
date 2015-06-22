
#ifndef PLAYER
# define PLAYER

# include <SFML/Graphics.hpp>
# include <utility>
# include <map>
  
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
