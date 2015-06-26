
#include "Graphics.hh"

Graphics::Graphics(std::pair<int, int>)
{
  this->app = new sf::RenderWindow(sf::VideoMode(1500, 1000, 32), "La Zapette !", 
				   sf::Style::Close | sf::Style::Titlebar);
  _view.SetCenter(sf::Vector2f(750, 500));
  _view.SetHalfSize(sf::Vector2f(750, 500));
  app->SetView(_view);
  _grassImage.LoadFromFile("./res/grass.jpg");
  _hightlightGrassImage.LoadFromFile("./res/grass_highlight.jpg");
  _scrollImage.LoadFromFile("./res/scroll.png");
  _backgroundImage.LoadFromFile("./res/bckgrnd.jpg");

  _ressourcesImage[FOOD].LoadFromFile("./res/food.png");
  _ressourcesImage[LINEMATE].LoadFromFile("./res/linemate.png"); 
  _ressourcesImage[DERAUMERE].LoadFromFile("./res/deraumere.png");
  _ressourcesImage[SIBUR].LoadFromFile("./res/sibur.png");
  _ressourcesImage[MENDIANE].LoadFromFile("./res/mendiane.png");
  _ressourcesImage[PHIRAS].LoadFromFile("./res/phiras.png");
  _ressourcesImage[THYSTAME].LoadFromFile("./res/thystame.png");
  
  _font.LoadFromFile("./res/font.ttf");
  _music.OpenFromFile("./res/bo.ogg");
  _music.Play();

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
  _zoomCoeff = 1;
  _offsetCoeff = sf::Vector2f(0, 0);
}

Graphics::~Graphics()
{
}

void				Graphics::printBackground()
{
  sf::Sprite			current;
  
  current.SetImage(_backgroundImage);
  current.SetPosition(_offsetCoeff);
  current.Resize(sf::Vector2f(1500, 1000));
  app->Draw(current);
  
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
  printBackground();
  cleanMap(map);
  highlightCase(map->getHud());
  printRessources(map);
  printEggs(map);
  printPlayers(map);
  printHud(map);
  app->Display();
}

void				Graphics::nothingToHud()
{
  sf::String			msg("Nothing\nto display !", _font, 20);
  
  msg.SetPosition(sf::Vector2f(1325, 500) + _offsetCoeff);
  msg.SetColor(sf::Color(0, 0, 0, 255));
  app->Draw(msg);
}

void				Graphics::printPlayerOnHud(Player *currentPlayer)
{
  sf::Sprite			currentRes;
  sf::String			currentString;
  std::stringstream		ss;
  int				y = 100;

  currentString.SetColor(sf::Color(0, 0, 0, 255));
  ss << currentPlayer->getLevel();
  currentString.SetSize(20);  
  currentString.SetFont(_font);
  currentString.SetText(std::string("Level : " + ss.str()));
  currentString.SetPosition(sf::Vector2f(1325,  y)+ _offsetCoeff);
  app->Draw(currentString);
  y+= 25;
  ss.str("");
  ss << currentPlayer->getPid();
  currentString.SetText(std::string("PlayerID : " + ss.str()));
  currentString.SetPosition(sf::Vector2f(1325,  y)+ _offsetCoeff);
  app->Draw(currentString);
  y+= 25;
  currentString.SetText(std::string("TeamName :\n" + currentPlayer->getTeamName()));
  currentString.SetPosition(sf::Vector2f(1325,  y)+ _offsetCoeff);
  app->Draw(currentString);
  currentRes.Scale(sf::Vector2f(0.1, 0.1));  
  y += 50;
  ss.str("");
  for (size_t i = 0; i != 7; i++)
    {
      ss << currentPlayer->askInventory((t_ressource)i);
      currentString.SetText(ss.str());
      currentString.SetPosition(sf::Vector2f(1350, y + 5) + _offsetCoeff);
      currentRes.SetImage(_ressourcesImage[(t_ressource)i]);
      currentRes.SetPosition(sf::Vector2f(1325, y) + _offsetCoeff);
      app->Draw(currentRes);
      app->Draw(currentString);
      y += 25;
      ss.str("");
    }
}

void				Graphics::printCaseOnHud(Case *currentCase)
{
  sf::Sprite			currentRes;
  sf::String			currentString;
  std::stringstream		ss;
  int				y = 500;

  currentRes.Scale(sf::Vector2f(0.1, 0.1));
  currentString.SetFont(_font);
  currentString.SetSize(10);
  currentString.SetColor(sf::Color(0, 0, 0, 255));
  ss << currentCase->getPos().first;
  ss << " x ";
  ss << currentCase->getPos().second;
  currentString.SetSize(20);
  currentString.SetText(std::string("Case at pos :\n" + ss.str()));
  currentString.SetPosition(sf::Vector2f(1325,  y)+ _offsetCoeff);
  app->Draw(currentString);
  ss.str("");
  y += 50;
  for (size_t i = 0; i != 7; i++)
    {
      ss << currentCase->askInventory((t_ressource)i);
      currentString.SetText(ss.str());
      currentString.SetPosition(sf::Vector2f(1350, y + 5) + _offsetCoeff);
      currentRes.SetImage(_ressourcesImage[(t_ressource)i]);
      currentRes.SetPosition(sf::Vector2f(1325, y) + _offsetCoeff);
      app->Draw(currentRes);
      app->Draw(currentString);
      y += 25;
      ss.str("");
    }
}

void				Graphics::highlightCase(std::pair<int, int> pos)
{
  sf::Sprite			current;
  
  if (pos.first < 0 || pos.second < 0)
    return ;
  current.SetImage(_hightlightGrassImage);
  current.SetPosition(sf::Vector2f(pos.first * 50, pos.second * 50));
  app->Draw(current);
  return ;
}

Player*				Graphics::getPlayerHightlight(std::pair<int, int> pos,
							      Map *map)
{
  Player			*current;

  if ((current = map->getPlayerFromPos(pos)) != NULL)
    {
      _playerHightLightId = current->getPid();
	return current;
    }
  else
    {
      return map->getPlayerFromId(_playerHightLightId);
    }
  return NULL;
}

void				Graphics::printHud(Map *map)
{
  sf::Sprite			scroll;
  Player			*currentPlayer = getPlayerHightlight(map->getHud(),
									  map);
  Case				*currentCase = map->getCaseFromPos(map->getHud());

  scroll.SetImage(_scrollImage);
  scroll.SetPosition(sf::Vector2f(1300, 0) + _offsetCoeff);
  app->Draw(scroll);
  if (currentPlayer != NULL)
    printPlayerOnHud(currentPlayer);
  if (currentCase != NULL)
    printCaseOnHud(currentCase);
  if (currentCase == NULL && currentPlayer == NULL)
    nothingToHud();
}

void				Graphics::printEggs(Map *map)
{
  sf::Sprite			currentSprite;
  Egg				*currentEgg;
  std::pair<int, int>		currentPos;

  for (size_t i = 0; (currentEgg = map->getEgg(i)) != NULL; i++)
    {
      currentPos = currentEgg->getPos();
      currentSprite.SetImage(*(currentEgg->getSkin()));
      currentSprite.SetPosition(sf::Vector2f(50 * currentPos.first, 50 * currentPos.second));
      app->Draw(currentSprite);
    }
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
      if (event.Type == sf::Event::MouseButtonReleased)
	{
	  if (event.MouseButton.Button == sf::Mouse::Left)
	    {
	      myEvent.eventName = CHFOCUS;
	      myEvent.posX = (event.MouseButton.X + _offsetCoeff.x) / (50 / _zoomCoeff); 
	      myEvent.posY = (event.MouseButton.Y + _offsetCoeff.y) / (50 / _zoomCoeff);
	    }
	}
      eventStack.push_back(myEvent);
    }
}

void			       Graphics::moveView(t_eventName key)
{
  if (key == SCROLLUP || key == SCROLLDOWN)
    {
      if (key == SCROLLUP)
	{
	  //	  _view.Zoom(0.9f);
	  _zoomCoeff -= 0.1;
	}	
      else
	{
	  //_view.Zoom(1.1f);
	  _zoomCoeff += 0.1;
	}
    }
  else
    _view.Move(_bindMove[key]);
  _offsetCoeff += _bindMove[key];
}
