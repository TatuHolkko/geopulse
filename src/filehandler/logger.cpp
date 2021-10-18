#include "logger.h"

#include <iostream>

Logger::Logger(const str &original, const str &stripped) : original_fileContent(original), internal_fileContent(stripped) 
{
}

void Logger::errorPoint(InternalPoint defect, const str &message)
{
    int location = getLocation(defect);
    ExternalRange lineContent = getLine(location);
    printError(lineContent, message);
}

void Logger::errorRange(InternalRange defect, const str &message)
{
    ExternalRange startLine = getLine(getLocation(defect.start));
    ExternalRange endLine = getLine(getLocation(defect.end));
    printError({startLine.start, endLine.end}, message);
}

void Logger::printError(ExternalRange defect, const str& message)
{
    printString("# Error on line ");
    printString(std::to_string(lineNumber(defect.start)));
    printString(":\n\n> \n> ");
    printRange({defect.start.iterator, defect.end.iterator}, true);
    printString("\n>\n\n# ");
    printString(message);
    printString("\n");
}

int Logger::getLocation(InternalPoint point)
{
    return std::distance(internal_fileContent.begin(), point.iterator);
}

int Logger::lineNumber(ExternalPoint point)
{
    int lineNumber = 1;
    str_cit current = original_fileContent.begin();

    while(current != point.iterator)
    {
        if (*current == '\n')
        {
            lineNumber++;
        }
        current = next(current);
    }

    return lineNumber;
}

ExternalRange Logger::getLine(int internalLocation)
{
    str_cit startOfLine = original_fileContent.begin();
    str_cit endOfLine = startOfLine;
    str_cit current = startOfLine;

    for (int i = 0; i < internalLocation; i++)
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
