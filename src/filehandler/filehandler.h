#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "../utility/utility.h"
#include <list>
#include <string>

class ParsingException: public std::exception
{
public:
  virtual const char* what() const throw();
};

void read(conf::Performance &performance, const std::string &filepath);

#endif