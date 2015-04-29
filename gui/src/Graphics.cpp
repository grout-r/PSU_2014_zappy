//
// Graphics.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:47:11 2015 grout_r
// Last update Tue Apr 28 15:24:32 2015 grout_r
//

#include "Graphics.hh"
#include <SFML/Graphics.hpp>

Graphics::Graphics()
{
  this->app = new sf::RenderWindow(sf::VideoMode(1000, 1000, 32), "La Zapette !");
}

Graphics::~Graphics()
{
}

Event				getEvent()
{
  return (Event());  
}
