#ifndef EGG
# define EGG

# include <utility>
# include <SFML/Graphics.hpp>

class				Egg
{
private:
  std::pair<int, int>		_pos;
  int				_eggId;
  int				_pid;
  sf::Image			*_skin;

public:
  Egg(int eggId, int pid, std::pair<int, int> pos);
  ~Egg();
  sf::Image*			getSkin();
  int				getId();
  int				getPid();
  std::pair<int, int>		getPos();
  
};
#endif
