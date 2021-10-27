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

/**
 * @brief Create a performance configuration from a file
 * 
 * @param performance conf::Performance struct to write to
 * @param filepath Filepath
 * 
 * @return True if the performance was written, false otherwise
 */
bool read(conf::Performance &performance, const std::string &filepath);

#endif