# include "Case.hh"

Case::Case(std::pair<int, int> pos) : _pos(pos)
{
}

Case::~Case()
{
}

std::pair<int ,int>				Case::getPos()
{
  return (_pos);
}

void						Case::setRessources(std::map<t_ressource, 
								    int> ressources)
{
  _ressources = ressources;
}

std::map<t_ressource, int>			Case::getRessources()
{
  return (_ressources);
}

int						Case::askInventory(t_ressource res)
{
  return (_ressources[res]);
}
