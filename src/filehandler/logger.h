#ifndef LOGGER_H
#define LOGGER_H

#include "utility.h"

#include <string>

/**
 * There are three kinds of location variable types:
 * 
 * Internal point: 
 *      iterator pointing to the original file content string,
 *      aka. the file content
 * 
 * External point: 
 *      iterator pointing to the stripped file content string,
 *      aka. the internal string that is parsed
 * 
 * Location:
 *      Integer representing a location by defining the number
 *      of preceding non-whitespace characters from the start
 *      of the file.
 */

typedef struct
{
    str_cit iterator;
} InternalPoint;

typedef struct
{
    str_cit iterator;
} ExternalPoint;

typedef struct
{
    InternalPoint start;
    InternalPoint end;
} InternalRange;

typedef struct
{
    ExternalPoint start;
    ExternalPoint end;
} ExternalRange;

class Logger
{
    const str &original_fileContent;
    const str &internal_fileContent;

    /**
     * @brief Return the line number of a given External point,
     *        starting from 1.
     * 
     * @param point
     * @return int
     */
    int lineNumber(ExternalPoint point);

    /**
     * @brief Get the line that contains the given location
     * 
     * @param location
     * @return ExternalRange
     */
    ExternalRange getLine(int location);

    /**
     * @brief Print a range to the standard output
     * 
     * @param message Range to print
     * @param indent if true, a "> " string will be prepended on each line
     */

    void printRange(StrRange message, bool indent);

    /**
     * @brief Print a string to the standard output
     * 
     * @param message String to print
     */
    void printString(const str &message);

    /**
     * @brief Get the number of non-whitespace characters before the 
     *        Internal point
     * 
     * @param point 
     * @return int 
     */
    int getLocation(InternalPoint point);

    /**
     * @brief Print an error with a message
     * 
     * @param defect The code segment that caused the error
     * @param message Error message
     */
    void printError(ExternalRange defect, const str &message);

public:
    /**
     * @brief Construct a new Logger object
     * 
     * @param original Raw file content
     * @param stripped The file content without any whitespace
     */
    Logger(const str &original, const str &stripped);

    /**
     * @brief Report an error at a single character
     * 
     * The whole line that contains the character will be printed
     * 
     * @param defect Internal point to the erroneous character
     * @param message Error message
     */
    void errorPoint(InternalPoint defect, const str &message);

    /**
     * @brief Report an erroneous code segment
     * 
     * All lines that the segment resides in are reported
     * 
     * @param defect Internal range to the erroneous code segment
     * @param message Error message
     */
    void errorRange(InternalRange defect, const str &message);
};

#endif