
#include "Graphics.hh"

Graphics::Graphics()
{
  this->app = new sf::RenderWindow(sf::VideoMode(800, 800, 32), "La Zapette !", 
				   sf::Style::Close | sf::Style::Titlebar);
  _grassImage.LoadFromFile("./res/grass.jpg");

  _ressourcesImage[FOOD].LoadFromFile("./res/food.png");
  _ressourcesImage[LINEMATE].LoadFromFile("./res/linemate.png"); 
  _ressourcesImage[DERAUMERE].LoadFromFile("./res/deraumere.png");
  _ressourcesImage[SIBUR].LoadFromFile("./res/sibur.png");
  _ressourcesImage[MENDIANE].LoadFromFile("./res/mendiane.png");
  _ressourcesImage[PHIRAS].LoadFromFile("./res/phiras.png");
  _ressourcesImage[THYSTAME].LoadFromFile("./res/thystame.png");
  
  _ressourcesPadding[FOOD] = sf::Vector2f(0 , 0);
  _ressourcesPadding[LINEMATE] = sf::Vector2f(16.666 , 0);
  _ressourcesPadding[DERAUMERE] = sf::Vector2f(33.333 , 0);
  _ressourcesPadding[SIBUR] = sf::Vector2f(0 , 16.666);
  _ressourcesPadding[MENDIANE] = sf::Vector2f(16.666 , 16.666);
  _ressourcesPadding[PHIRAS] = sf::Vector2f(33.333 , 16.666);
  _ressourcesPadding[THYSTAME] = sf::Vector2f(0 , 33.333);
  
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
  app->Clear();
  cleanMap(map);
  printPlayers(map);
  printRessources(map);
  app->Display();
}

void				Graphics::printPlayers(Map *map)
{
  sf::Sprite			*current;

  for (size_t i = 0; (current = map->getPlayerSprite(i)) != NULL; i++)
    {
      app->Draw(*current);
      delete current;
    }
}

void				Graphics::printThisRessourceAtPos(t_ressource res,
								   std::pair<int, int> pos)
{
  sf::Sprite			current;
  
  current.SetImage(_ressourcesImage[res]);
  current.SetPosition(sf::Vector2f(pos.first * 50,  pos.second * 50));
  current.Move(_ressourcesPadding[res]);
  current.Scale(sf::Vector2f(0.0833, 0.0833));
  app->Draw(current);
}

void				Graphics::printRessources(Map *map)
{
  Case				*currentCase;
  std::map<t_ressource, int>	currentMap;
  t_ressource			currentRes;

  for (size_t i = 0; (currentCase = map->getCase(i)) != NULL; i++)
    {
      currentMap = currentCase->getRessources();
      for (int j = 0; j != 7; j++)
	{
	  currentRes = (t_ressource)j;
	  if (currentMap[currentRes] > 0)
	    printThisRessourceAtPos(currentRes, currentCase->getPos());
	  //	    (this->*_bindPrintRsPtr[currentRes])(currentCase->getPos());
	}
    }
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
