# include "Egg.hh"

Egg::Egg(int eggId, int pid, std::pair<int, int> pos) : 
  _pos(pos), _eggId(eggId), _pid(pid)
{
  _skin = new sf::Image;
  _skin->LoadFromFile("./res/egg.png");
}

Egg::~Egg()
{
}

sf::Image*			Egg::getSkin()
{
  return (_skin);
}

int				Egg::getId()
{
  return (_eggId);
}

int				Egg::getPid()
{
  return (_pid);
}

std::pair<int, int>		Egg::getPos()
{
  return (_pos);
}

