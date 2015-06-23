
#include "Graphics.hh"

Graphics::Graphics(std::pair<int, int> size)
{
  this->app = new sf::RenderWindow(sf::VideoMode(1500, 1000, 32), "La Zapette !", 
				   sf::Style::Close | sf::Style::Titlebar);
  _view.SetCenter(sf::Vector2f((size.first / 2) * 50, (size.second / 2) * 50));
  _view.SetHalfSize(sf::Vector2f(750, 500));
  app->SetView(_view);
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

  _bindMove[KEYUP] = sf::Vector2f(0, -50);
  _bindMove[KEYDOWN] = sf::Vector2f(0, 50);
  _bindMove[KEYLEFT] = sf::Vector2f(-50, 0);
  _bindMove[KEYRIGHT] = sf::Vector2f(50, 0);

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

void				Graphics::handleEvent(std::vector<Event> &eventStack)
{
  sf::Event				event;
  Event					myEvent;

  while (this->app->GetEvent(event))
    {
      if (event.Type == sf::Event::Closed)
  	exit(0);
      if (event.Type == sf::Event::KeyPressed)
  	{
  	  if (event.Key.Code == sf::Key::Left)
	    myEvent.eventName = KEYLEFT;
  	  if (event.Key.Code == sf::Key::Right)
	    myEvent.eventName = KEYRIGHT;
  	  if (event.Key.Code == sf::Key::Up)
	    myEvent.eventName = KEYUP;
  	  if (event.Key.Code == sf::Key::Down)
	    myEvent.eventName = KEYDOWN;
  	}
      if (event.Type == sf::Event::MouseWheelMoved)
	{
	  if (event.MouseWheel.Delta == 1)
	    myEvent.eventName = SCROLLUP;
	  if (event.MouseWheel.Delta == -1)
	    myEvent.eventName = SCROLLDOWN;
	}
      eventStack.push_back(myEvent);
    }
}

void			       Graphics::moveView(t_eventName key)
{
  (void)key;
  if (key == SCROLLUP || key == SCROLLDOWN)
    {
      if (key == SCROLLUP)
	_view.Zoom(0.9f);
      else
	_view.Zoom(1.1f);	
    }
  else
    _view.Move(_bindMove[key]);
}
