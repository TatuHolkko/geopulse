#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>

class InputParser
{
private:
    std::vector<std::string> tokens;

public:
    /**
     * @brief Construct a new Input Parser object
     * 
     * @param argc argc from main function arguments
     * @param argv argv from main function arguments
     */
    InputParser(int &argc, char **argv);
    
    /**
     * @brief Get the value of a given option
     * 
     * For example if the execution command contains a "-f filename.txt",
     * calling this function with "f" as the argument will return 
     * "filename.txt"
     * 
     * @param option the name of the option
     * @return const std::string& the value of the option
     */
    const std::string &getCmdOption(const std::string &option) const;

    /**
     * @brief Return true if the given option was used
     * 
     * @param option the name of the option
     * @return true if the given option exists
     * @return false if the given option does not exist
     */
    bool cmdOptionExists(const std::string &option) const;
};

#endif