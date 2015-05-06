//
// Graphics.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:47:11 2015 grout_r
// Last update Tue May  5 14:23:44 2015 grout_r
//

#include "Graphics.hh"

void			Graphics::resetMap()
{
  std::vector<sf::Sprite*>	tmp;

  if (this->map.size() != 0)
    {
      for (size_t j = 0; j != this->map.size(); j++)
	for (size_t k = 0; k != this->map[j].size(); k++)
	  this->printGrass(this->map[j][k]);
    }
  else
    {
      for (int y = 0; y != 16; y++)
	{
	  for (int i = 0; i != 16; i++)
	    {
	      tmp.push_back(new sf::Sprite());
	      tmp.back()->SetImage(this->grass);
	      tmp.back()->SetPosition(sf::Vector2f(50 * y, 50 * i));
	      this->app->Draw(*(tmp.back()));
	    }
	  this->map.push_back(std::vector<sf::Sprite*>(tmp));
	  tmp.clear();
	}
    }
}

Graphics::Graphics()
{
  this->app = new sf::RenderWindow(sf::VideoMode(800, 800, 32), "La Zapette !", 
				   sf::Style::Close | sf::Style::Titlebar);
  this->grass.LoadFromFile("./res/grass.jpg");
  this->resetMap();
}

Graphics::~Graphics()
{
}

void				Graphics::handleEvent()
{
  sf::Event				event;
  Player				*tmp = this->getPlayerFromId(1);

  while (this->app->GetEvent(event))
    {
      if (event.Type == sf::Event::Closed)
	exit(0);
      if (event.Type == sf::Event::KeyPressed)
	{
	  if (event.Key.Code == sf::Key::Left)
	    movePlayer(1, std::make_pair(tmp->getPos().first-1, tmp->getPos().second), WEST);
	  if (event.Key.Code == sf::Key::Right)
	    movePlayer(1, std::make_pair(tmp->getPos().first+1, tmp->getPos().second), EAST);
	  if (event.Key.Code == sf::Key::Up)
	    movePlayer(1, std::make_pair(tmp->getPos().first,tmp->getPos().second-1), NORTH);
	  if (event.Key.Code == sf::Key::Down)
	    movePlayer(1, std::make_pair(tmp->getPos().first, tmp->getPos().second+1),SOUTH);
	}
    }
}

void				Graphics::refreshScreen()
{
  this->resetMap();
  for (size_t i = 0; i != this->players.size(); i++)
    this->printPlayer(this->players[i]);
  this->app->Display();
}

void				Graphics::printGrass(sf::Sprite *currentCase)
{
  currentCase->SetImage(this->grass);
  this->app->Draw(*currentCase);  
}

Player*				Graphics::getPlayerFromId(int pid)
{
  for (size_t i = 0; i != this->players.size(); i++)
    {
      if (this->players[i]->getPid() == pid)
	return (this->players[i]);
    }
  return NULL;
}

void				Graphics::printPlayer(Player *tmpPlayer)
{
  std::pair<int, int>		tmpPos = tmpPlayer->getPos();
  sf::Sprite			currentCase;

  currentCase.SetPosition(sf::Vector2f(50 * tmpPos.first, tmpPos.second * 50));
  currentCase.SetImage(*(tmpPlayer->getSkin()));
  currentCase.SetSubRect(tmpPlayer->getIntRectFromOrientation());
  this->app->Draw(currentCase);
}

void				Graphics::movePlayer(int pid, std::pair<int ,int> pos, 
						     t_orientation orientation)
{
  Player			*tmpPlayer = this->getPlayerFromId(pid);
  
  tmpPlayer->setPos(pos);
  tmpPlayer->setOrientation(orientation);
}

void				Graphics::addPlayer(int pid, std::pair<int, int> pos,
						    t_orientation orientation, int level,
						    std::string teamName)
{
  Player			*bob = new Player(pid, pos, orientation, level, teamName);
   
  this->players.push_back(bob);  
}
