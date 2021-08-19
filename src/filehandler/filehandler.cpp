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

bool operator==(const StrRange &lhs, const str &rhs)
{

    if (std::distance(lhs.start, lhs.end) != std::distance(rhs.begin(), rhs.end()))
    {
        return false;
    }

    str_cit lhs_current = lhs.start;
    str_cit rhs_current = rhs.begin();

    while (lhs_current != lhs.end)
    {
        if (*lhs_current != *rhs_current)
        {
            return false;
        }
        lhs_current++;
        rhs_current++;
    }
    return true;
}

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

float evaluate(str_cit start, str_cit end)
{
    str buffer = "";
    str_cit current = start;
    while (current != end)
    {
        buffer.push_back(*current);
        current++;
    }
    return std::stof(buffer);
}

void configureProperty(FunctionProperty &property, str_cit confStart, str_cit confEnd)
{
    str_cit current = confStart;
    while (current < confEnd)
    {
        Section sect = getNextSection(current, confEnd);

        if (sect.name == "base")
        {
            property.base = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "dShape")
        {
            property.dShape = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "dVertex")
        {
            property.dVertex = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "ddVertex")
        {
            property.ddVertex = evaluate(sect.content.start, sect.content.end);
        }
        else
        {
            throw "Invalid function property configuration";
        }

        current = next(sect.content.end);
    }
}

void configureFunction(Function &function, str_cit confStart, str_cit confEnd)
{
    str_cit current = confStart;

    while (current < confEnd)
    {
        Section sect = getNextSection(current, confEnd);

        if (sect.name == "phase")
        {
            configureProperty(function.phase, sect.content.start, sect.content.end);
        }
        else if (sect.name == "period")
        {
            configureProperty(function.period, sect.content.start, sect.content.end);
        }
        else if (sect.name == "amplitude")
        {
            configureProperty(function.amplitude, sect.content.start, sect.content.end);
        }
        else if (sect.name == "offset")
        {
            configureProperty(function.offset, sect.content.start, sect.content.end);
        }
        else if (sect.name == "function")
        {
            if (sect.content == "sine")
            {
                function.type = Sine;
            }
            else if (sect.content == "halfsine")
            {
                function.type = HalfSine;
            }
            else
            {
                throw "Invalid function type";
            }
        }
        else
        {
            throw "Invalid function configuration";
        }

        current = next(sect.content.end);
    }
}

ShapeGroup createGroup(str_cit start, str_cit end)
{
    ShapeGroup group = {.vertices = 6,
                        .amount = 1,
                        .angle = {
                            .type = Sine,
                            .phase = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .amplitude = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .offset = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                        },
                        .radius = {
                            .type = Sine,
                            .phase = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .amplitude = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .offset = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                        },
                        .red = {
                            .type = Sine,
                            .phase = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .amplitude = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .offset = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                        },
                        .green = {
                            .type = Sine,
                            .phase = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .amplitude = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .offset = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                        },
                        .blue = {
                            .type = Sine,
                            .phase = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .amplitude = {.base = 0, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                            .offset = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0},
                        }};

    str_cit current = start;
    while (current < end)
    {
        Section sect = getNextSection(current, end);

        if (sect.name == "amount")
        {
            group.amount = evaluate(sect.content.start, sect.content.end);
        } else if (sect.name == "vertices")
        {
            group.vertices = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "angle")
        {
            configureFunction(group.angle, sect.content.start, sect.content.end);
        }
        else if (sect.name == "radius")
        {
            configureFunction(group.radius, sect.content.start, sect.content.end);
        }
        else if (sect.name == "red")
        {
            configureFunction(group.red, sect.content.start, sect.content.end);
        }
        else if (sect.name == "green")
        {
            configureFunction(group.green, sect.content.start, sect.content.end);
        }
        else if (sect.name == "blue")
        {
            configureFunction(group.blue, sect.content.start, sect.content.end);
        }
        else
        {
            throw "Invalid shape group configuration";
        }

        current = next(sect.content.end);
    }

    return group;
}

Phrase createPhrase(str_cit start, str_cit end)
{
    Phrase phrase = {
        .duration = 16,
        .groups = {}};

    str_cit current = start;

    while (current < end)
    {
        Section sect = getNextSection(current, end);

        if (sect.name == "duration")
        {
            phrase.duration = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "shapes")
        {
            phrase.groups.push_back(createGroup(sect.content.start, sect.content.end));
        }
        else
        {
            throw "Invalid scene configuration";
        }

        current = next(sect.content.end);
    }

    return phrase;
}

Performance createPerformance(const str &text)
{
    Performance perf = {
        .bpm = 120,
        .phrases = {}};

    str_cit start = text.begin();
    str_cit end = text.end();

    str_cit current = start;
    while (current < end)
    {
        Section sect = getNextSection(current, end);

        if (sect.name == "bpm")
        {
            perf.bpm = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "scene")
        {
            perf.phrases.push_back(createPhrase(sect.content.start, sect.content.end));
        }
        else
        {
            throw "Invalid scene configuration";
        }

        current = next(sect.content.end);
    }

    return perf;
}

Performance read(const str &filepath)
{
    std::ifstream ifs(filepath);

    str content((std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));

    strip(content);

    Performance perf = createPerformance(content);

    return perf;
}