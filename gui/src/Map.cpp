# include "Map.hh"

Map::Map(std::pair<int, int> size) : _size(size)
{
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

Case*				Map::getCase(size_t i)
{
  if (i > _cases.size() - 1 || _cases.size() == 0)
    return (NULL);
  return (_cases[i]);
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
