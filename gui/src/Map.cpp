# include "Map.hh"

Map::Map(std::pair<int, int> size) : _size(size), _hudLookAt(-1, -1)
{
}

void				Map::setHud(std::pair<int, int> pos)
{
  _hudLookAt = pos;
}

std::pair<int, int>	        Map::getHud()
{
  return (_hudLookAt);
}

sf::Sprite*			Map::getPlayerSprite(size_t i)
{
  Player			*tmpPlayer;
  std::pair<int, int>		tmpPos;
  sf::Sprite*			currentCase = new sf::Sprite();

  if (players.size() - 1 < i)
    return (NULL);
  tmpPlayer = players[i];
  tmpPos = tmpPlayer->getPos();
  currentCase->SetPosition(sf::Vector2f(50 * tmpPos.first, tmpPos.second * 50));
  currentCase->SetImage(*(tmpPlayer->getSkin()));
  currentCase->SetSubRect(tmpPlayer->getIntRectFromOrientation());
  return (currentCase);
}

Egg*				Map::getEgg(size_t i)
{
  if (i > _eggs.size() - 1 || _eggs.size() == 0)
    return (NULL);
  return (_eggs[i]);  
}

Case*				Map::getCase(size_t i)
{
  if (i > _cases.size() - 1 || _cases.size() == 0)
    return (NULL);
  return (_cases[i]);
}

Case*				Map::getCaseFromPos(std::pair<int, int> pos)
{
  for (size_t i = 0; i != _cases.size(); i++)
    {
      if (_cases[i]->getPos() == pos)
	return (_cases[i]);
    }
  return (NULL);  
}

Player*				Map::getPlayerFromId(int id)
{
  for (size_t i = 0; i != players.size(); i++)
    {
      if (players[i]->getPid() == id)
	return (players[i]);
    }
  return (NULL);
}

Player*				Map::getPlayerFromPos(std::pair<int, int> pos)
{
  for (size_t i = 0; i != players.size(); i++)
    {
      if (players[i]->getPos() == pos)
	return (players[i]);
    }
  return (NULL);
}

void				Map::movePlayer(int pid, std::pair<int ,int> pos, 
						     t_orientation orientation)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->setPos(pos);
  tmpPlayer->setOrientation(orientation);
}

void				Map::updateInventory(int pid, 
						     std::map<t_ressource, int> newInv)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->updateInventory(newInv);
}

void				Map::pexPlayer(int pid, int level)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);

  if (tmpPlayer == NULL)
    return ;
  tmpPlayer->setLevel(level);
}

void				Map::addPlayer(int pid, std::pair<int, int> pos,
						    t_orientation orientation, int level,
						    std::string teamName)
{
  Player			*bob = new Player(pid, pos, orientation, level, teamName);
  
  this->players.push_back(bob);  
}

void				Map::addEgg(int eggId, int pid, std::pair<int, int> pos)
{
  _eggs.push_back(new Egg(eggId, pid, pos));
}

std::pair<int, int>		Map::getSize()
{
  return (_size);
}

void				Map::resizeMap(std::pair<int ,int> newSize)
{
  _size = newSize;
}

void			        Map::updateCase(std::pair<int, int> pos,
						std::map<t_ressource, int> res)
{
  for(size_t i = 0; i != _cases.size(); i++)
    {
      if (pos == _cases[i]->getPos())
      	{
	  _cases[i]->setRessources(res);
	  return ;
      	}
    }
  _cases.push_back(new Case(pos));
  _cases.back()->setRessources(res);
}
