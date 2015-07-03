# include "Case.hh"

Case::Case(std::pair<int, int> pos) : _pos(pos), _status(NO)
{
}

Case::~Case()
{
}

std::pair<int ,int>				Case::getPos()
{
  return (_pos);
}

void						Case::setRessources(std::map<t_ressource, 
								    int> ressources)
{
  _ressources = ressources;
}

std::map<t_ressource, int>			Case::getRessources()
{
  return (_ressources);
}

int						Case::askInventory(t_ressource res)
{
  return (_ressources[res]);
}

t_incant				        Case::getStatus()
{
  return (_status);
}

void						Case::startIncant()
{
  _status = PROCESS;
  _timer.Reset();
}

void						Case::update()
{
  if (_status == PASSED || _status == FAILED)
    if (_timer.GetElapsedTime() > 2)
      _status = NO;
}

void						Case::resultIncant(bool res)
{
  if (res == true)
    _status = FAILED;
  if (res == false)
    _status = PASSED;
  _timer.Reset();  
}

