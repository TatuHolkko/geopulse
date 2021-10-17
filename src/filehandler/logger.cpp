#include "logger.h"

#include <iostream>

Logger::Logger(const str &original, const str &stripped) : original_fileContent(original), internal_fileContent(stripped) 
{
}

void Logger::errorPoint(str_cit iterator, const str &message)
{
    int startLocation = getLocation(iterator);
    StrRange line = getLine(startLocation);
    errorRange(line, message);
}

void Logger::errorRange(StrRange range, const str &message)
{
    int startLocation = getLocation(range.start);
    int lineNum = lineNumber(startLocation);
    printString("# Error on line ");
    printString(std::to_string(lineNum));
    printString(":\n\n> \n> ");
    printRange(range, true);
    printString("\n>\n\n# ");
    printString(message);
    printString("\n");
}

int Logger:: getLocation(str_cit internalLocation)
{
    return std::distance(internal_fileContent.begin(), internalLocation);
}

int Logger::lineNumber(int location)
{
    int lineNumber = 1;
    str_cit current = original_fileContent.begin();

    while(*current == ' ' || *current == '\n' || *current == '\t')
    {
        if (*current == '\n')
        {
            lineNumber++;
        }
        current = next(current);
    }

    for (int i = 0; i < location; i++)
    {
        current = next(current);

        while(*current == ' ' || *current == '\n' || *current == '\t')
        {
            if (*current == '\n')
            {
                lineNumber++;
            }
            current = next(current);
        }
    }

    return lineNumber;
}

StrRange Logger::getLine(int location)
{
    str_cit startOfLine = original_fileContent.begin();
    str_cit endOfLine = startOfLine;
    str_cit current = startOfLine;

    for (int i = 0; i < location; i++)
    {
        current = next(current);
        while(*current == ' ' || *current == '\n' || *current == '\t')
        {
            if (*current == '\n')
            {
                startOfLine = next(current);
            }
            current = next(current);
        }
    }

    while(current != original_fileContent.end())
    {
        if(*current == '\n')
        {
            endOfLine = current;
            break;
        }
        current = next(current);
    }

    return {startOfLine, endOfLine};
}

void Logger::printRange(StrRange message, bool indent)
{
    str_cit current = message.start;
    while (current != message.end)
    {
        std::cout << *current;
        if(indent && *current == '\n')
        {
            std::cout << "> ";
        }
        current = next(current);
    }
}

void Logger::printString(const str& message)
{
    std::cout << message;
}

void Logger::step(str_cit &iterator)
{
    do
    {
        iterator = next(iterator);
    } while (*iterator == ' ' || *iterator == '\n' || *iterator == '\t');
}
