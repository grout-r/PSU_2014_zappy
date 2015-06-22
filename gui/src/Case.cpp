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

void						Case::dumpRessources()
{
  std::cout << "Case en " << _pos.first << " * " << _pos.second << " " ;   
  for (int i = 0; i != 7; i++)
    {
      std::cout
	<< " | Rs# : " << i 
	<< " --  " << _ressources[(t_ressource)i] ;
    }
  std::cout << std::endl;
}
