#ifndef CASE
#define CASE

# include <utility>
# include <map>
# include "Definition.hh"

class					Case
{
private:
  std::pair<int, int>			_pos;
  std::map<t_ressource, int>		_ressources;

public:
  Case(std::pair<int, int>);
  ~Case();
  std::pair<int, int>			getPos();
  void					setRessources(std::map<t_ressource, int>);
};

#endif
