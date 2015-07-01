
#include "Player.hh"

Player::Player(int pid, std::pair<int, int> pos, t_orientation orientation,
	       int level, std::string teamName) : 
  pid(pid), pos(pos), orientation(orientation), level(level), teamName(teamName)
{
  this->skin = new sf::Image;
  this->skin->LoadFromFile("./res/default_skin.png");
  this->IntRectFromOrientation[NORTH] = sf::IntRect(0, 150, 50, 200);
  this->IntRectFromOrientation[EAST] = sf::IntRect(0, 100, 50, 150);
  this->IntRectFromOrientation[WEST] = sf::IntRect(0, 50, 50, 100);
  this->IntRectFromOrientation[SOUTH] = sf::IntRect(0, 0, 50, 50);
  _inventaire[FOOD] = 0;
  _inventaire[LINEMATE] = 0;
  _inventaire[DERAUMERE] = 0;
  _inventaire[SIBUR] = 0;
  _inventaire[MENDIANE] = 0;
  _inventaire[PHIRAS] = 0;
  _inventaire[THYSTAME] = 0;
  _broadcasting = false;
}

Player::~Player()
{}

std::string			Player::getTeamName()
{
  return (teamName);
}

std::pair<int, int>		Player::getPos()
{
  return (this->pos);
}

int				Player::getPid()
{
  return (this->pid);
}

int				Player::getLevel()
{
  return (level);
}

void				Player::setLevel(int level)
{
  this->level = level;
}

void				Player::setPos(std::pair<int, int> newPos)
{
  this->pos = newPos;
}

sf::Image*			Player::getSkin()
{
  return (this->skin);
}

void				Player::setOrientation(t_orientation orientation)
{
  this->orientation = orientation;
}

sf::IntRect			Player::getIntRectFromOrientation()
{
  return (this->IntRectFromOrientation[this->orientation]);
}

void				Player::updateInventory(std::map<t_ressource, int> newInv)
{
  _inventaire = newInv;
}

int				Player::askInventory(t_ressource res)
{
  return (_inventaire[res]);
}

bool				Player::getBroadcast()
{
  return (_broadcasting);
}

void				Player::startBroadcast()
{
  _broadcasting = true;
  _timer.Reset();
}

void				Player::update()
{
  if (_broadcasting == true)
    if (_timer.GetElapsedTime() > 1.5)
      _broadcasting = false;
}
