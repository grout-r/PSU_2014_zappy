
# include "Exception.hh"

Error::Error(std::string const& msg) : message(msg) 
{}

Error::~Error() throw() {}

const char*				Error::what() const throw()
{
  return (this->message.c_str());
}
