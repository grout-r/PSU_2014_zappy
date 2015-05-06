//
// Player.cpp for zapppy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Thu Apr 30 14:16:26 2015 grout_r
// Last update Tue May  5 14:18:59 2015 grout_r
//

# include "Player.hh"

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
}

Player::~Player()
{}

std::pair<int, int>		Player::getPos()
{
  return (this->pos);
}

int				Player::getPid()
{
  return (this->pid);
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
