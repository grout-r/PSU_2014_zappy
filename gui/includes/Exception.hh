//
// Exception.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Wed May  6 09:57:14 2015 grout_r
// Last update Wed May  6 10:05:16 2015 grout_r
//

#ifndef EXCEPTION
# define EXCEPTION

# include <string>

class					Error : public std::exception
{
private:
  std::string message;
public:
  Error(std::string const& message);
  ~Error() throw();
  const char*				what() const throw();
};

#endif
