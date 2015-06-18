
#include "Graphics.hh"

Graphics::Graphics()
{
  this->app = new sf::RenderWindow(sf::VideoMode(800, 800, 32), "La Zapette !", 
				   sf::Style::Close | sf::Style::Titlebar);
  _grassImage.LoadFromFile("./res/grass.jpg");
}

Graphics::~Graphics()
{
}

void				Graphics::cleanMap(Map *map)
{
  sf::Sprite			tmp;
  std::pair<int, int>		mapSize = map->getSize();

 for (int x = 0; x != mapSize.first; x++)
    for (int y = 0; y != mapSize.second; y++)
      { 
	tmp.SetImage(_grassImage);
	tmp.SetPosition(sf::Vector2f(50 * x, 50 * y));
	app->Draw(tmp);
      }
}

void				Graphics::refreshScreen(Map *map)
{
  sf::Sprite			*current;

  app->Clear();
  cleanMap(map);
  for (size_t i = 0; (current = map->getPlayerSprite(i)) != NULL; i++)
    {
      app->Draw(*current);
      delete current;
    }
  app->Display();
}

void				Graphics::handleEvent()
{
  // sf::Event				event;
  // Player				*tmp = this->getPlayerFromId(1);

  // while (this->app->GetEvent(event))
  //   {
  //     if (event.Type == sf::Event::Closed)
  // 	exit(0);
  //     if (event.Type == sf::Event::KeyPressed)
  // 	{
  // 	  if (event.Key.Code == sf::Key::Left)
  // 	    movePlayer(1, std::make_pair(tmp->getPos().first-1, tmp->getPos().second), WEST);
  // 	  if (event.Key.Code == sf::Key::Right)
  // 	    movePlayer(1, std::make_pair(tmp->getPos().first+1, tmp->getPos().second), EAST);
  // 	  if (event.Key.Code == sf::Key::Up)
  // 	    movePlayer(1, std::make_pair(tmp->getPos().first,tmp->getPos().second-1), NORTH);
  // 	  if (event.Key.Code == sf::Key::Down)
  // 	    movePlayer(1, std::make_pair(tmp->getPos().first, tmp->getPos().second+1),SOUTH);
  // 	}
  //   }
}
