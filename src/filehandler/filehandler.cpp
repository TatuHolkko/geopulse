#include "filehandler.h"

#include <fstream>
#include <algorithm>
#include <sstream>

typedef std::string str;
typedef str::const_iterator str_cit;

typedef struct StrRange
{
    str_cit start;
    str_cit end;
} StrRange;

typedef struct Section
{
    StrRange name;
    StrRange content;
} Section;

void strip(str &content)
{
    str::iterator end_pos;

    end_pos = std::remove(content.begin(), content.end(), ' ');
    end_pos = std::remove(content.begin(), end_pos, '\t');
    end_pos = std::remove(content.begin(), end_pos, '\n');

    content.erase(end_pos, content.end());
}

str_cit findFirst(str_cit start, str_cit end, std::list<char> chars)
{
    str_cit result = end;
    for (char c : chars)
    {
        str_cit candidate = find(start, end, c);
        if (candidate < result)
        {
            result = candidate;
        }
    }
    return result;
}

str_cit matchingBracket(str_cit start, str_cit end)
{
    int depth = 0;
    str_cit current = next(start);
    while (current != end)
    {
        if (*current == '{')
        {
            depth++;
        }
        else if (*current == '}')
        {
            if (depth == 0)
            {
                return current;
            }
            depth--;
        }
        current++;
    }
    throw "No matching bracket found";
}

Section getNextSection(str_cit start, str_cit end)
{
    str_cit blockStart = findFirst(start, end, {':', '{'});
    if (blockStart == end)
    {
        throw "Invalid section";
    }

    str_cit blockEnd;
    if (*blockStart == '{')
    {
        blockEnd = matchingBracket(blockStart, end);
    }
    else
    {
        blockEnd = findFirst(blockStart, end, {';'});
        if (blockEnd == end)
        {
            throw "Missing ;";
        }
    }

    StrRange name = {start, blockStart};
    StrRange content = {next(blockStart), blockEnd};

    return {name, content};
}

void read(const str &filepath)
{
    std::ifstream ifs(filepath);

    str content((std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));

    strip(content);

    Section sec = getNextSection(content.begin(), content.end());

    std::stringstream buff;
    buff.write(&(*(sec.content.start)), std::distance(sec.content.start, sec.content.end));

    printf("%s\n", buff.str().c_str());
}