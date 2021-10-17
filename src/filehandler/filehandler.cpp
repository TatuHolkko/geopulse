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

typedef struct Deviator
{
    float base = 0;
    float dShape = 0;
    float dVertex = 0;
    float ddVertex = 0;
} Deviator;

typedef struct Function
{
    FunctionType type = Sine;
    Deviator phase;
    Deviator period = {.base = 1, .dShape = 0, .dVertex = 0, .ddVertex = 0};
    Deviator amplitude;
    Deviator offset;
} Function;

const conf::Cluster defaultCluster = {.vertices = 6,
                                      .amount = 1,
                                      .angle = {.type = Sine, .paramSequenceSequence = {.base = {.base = {.phase = 0, .period = 1, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}, .delta = {.base = {.phase = 0, .period = 0, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}}},

                                      .radius = {.type = Sine, .paramSequenceSequence = {.base = {.base = {.phase = 0, .period = 1, .amp = 0, .offset = 0.5}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0.1}}, .delta = {.base = {.phase = 0, .period = 0, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}}},

                                      .red = {.type = Sine, .paramSequenceSequence = {.base = {.base = {.phase = 0, .period = 1, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}, .delta = {.base = {.phase = 0, .period = 0, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}}},

                                      .green = {.type = Sine, .paramSequenceSequence = {.base = {.base = {.phase = 0, .period = 1, .amp = 0, .offset = 1}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}, .delta = {.base = {.phase = 0, .period = 0, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}}},

                                      .blue = {.type = Sine, .paramSequenceSequence = {.base = {.base = {.phase = 0, .period = 1, .amp = 0, .offset = 1}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}, .delta = {.base = {.phase = 0, .period = 0, .amp = 0, .offset = 0}, .delta = {.phase = 0, .period = 0, .amp = 0, .offset = 0}}}}};

const conf::Phrase defaultPhrase = {
    .duration = 16,
    .clusters = {}};

const conf::Performance defaultPerformance = {
    .bpm = 120,
    .phrases = {}};

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

void configureDeviator(Deviator &deviator, str_cit confStart, str_cit confEnd)
{
    str_cit current = confStart;
    while (current < confEnd)
    {
        Section sect = getNextSection(current, confEnd);

        if (sect.name == "base")
        {
            deviator.base = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "dShape")
        {
            deviator.dShape = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "dVertex")
        {
            deviator.dVertex = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "ddVertex")
        {
            deviator.ddVertex = evaluate(sect.content.start, sect.content.end);
        }
        else
        {
            throw "Invalid Deviator property";
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
            configureDeviator(function.phase, sect.content.start, sect.content.end);
        }
        else if (sect.name == "period")
        {
            configureDeviator(function.period, sect.content.start, sect.content.end);
        }
        else if (sect.name == "amplitude")
        {
            configureDeviator(function.amplitude, sect.content.start, sect.content.end);
        }
        else if (sect.name == "offset")
        {
            configureDeviator(function.offset, sect.content.start, sect.content.end);
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

void convertToInternalConf(conf::DeviatorSequenceSequence &internalConf, Function &fileConf)
{
    internalConf.type = fileConf.type;

    internalConf.paramSequenceSequence.base.base.phase = fileConf.phase.base;
    internalConf.paramSequenceSequence.base.delta.phase = fileConf.phase.dVertex;
    internalConf.paramSequenceSequence.delta.base.phase = fileConf.phase.dShape;
    internalConf.paramSequenceSequence.delta.delta.phase = fileConf.phase.ddVertex;

    internalConf.paramSequenceSequence.base.base.period = fileConf.period.base;
    internalConf.paramSequenceSequence.base.delta.period = fileConf.period.dVertex;
    internalConf.paramSequenceSequence.delta.base.period = fileConf.period.dShape;
    internalConf.paramSequenceSequence.delta.delta.period = fileConf.period.ddVertex;

    internalConf.paramSequenceSequence.base.base.amp = fileConf.amplitude.base;
    internalConf.paramSequenceSequence.base.delta.amp = fileConf.amplitude.dVertex;
    internalConf.paramSequenceSequence.delta.base.amp = fileConf.amplitude.dShape;
    internalConf.paramSequenceSequence.delta.delta.amp = fileConf.amplitude.ddVertex;

    internalConf.paramSequenceSequence.base.base.offset = fileConf.offset.base;
    internalConf.paramSequenceSequence.base.delta.offset = fileConf.offset.dVertex;
    internalConf.paramSequenceSequence.delta.base.offset = fileConf.offset.dShape;
    internalConf.paramSequenceSequence.delta.delta.offset = fileConf.offset.ddVertex;
}

void configureCluster(conf::Cluster &cluster, str_cit start, str_cit end)
{

    str_cit current = start;
    while (current < end)
    {
        Section sect = getNextSection(current, end);

        if (sect.name == "amount")
        {
            cluster.amount = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "vertices")
        {
            cluster.vertices = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "angle")
        {
            Function f;
            configureFunction(f, sect.content.start, sect.content.end);
            convertToInternalConf(cluster.angle, f);
        }
        else if (sect.name == "radius")
        {
            Function f;
            configureFunction(f, sect.content.start, sect.content.end);
            convertToInternalConf(cluster.radius, f);
        }
        else if (sect.name == "red")
        {
            Function f;
            configureFunction(f, sect.content.start, sect.content.end);
            convertToInternalConf(cluster.red, f);
        }
        else if (sect.name == "green")
        {
            Function f;
            configureFunction(f, sect.content.start, sect.content.end);
            convertToInternalConf(cluster.green, f);
        }
        else if (sect.name == "blue")
        {
            Function f;
            configureFunction(f, sect.content.start, sect.content.end);
            convertToInternalConf(cluster.blue, f);
        }
        else
        {
            throw "Invalid Cluster property";
        }

        current = next(sect.content.end);
    }
}

void configurePhrase(conf::Phrase &phrase, str_cit start, str_cit end)
{

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
            phrase.clusters.push_back(defaultCluster);
            configureCluster(phrase.clusters.back(), sect.content.start, sect.content.end);
        }
        else
        {
            throw "Invalid scene configuration";
        }

        current = next(sect.content.end);
    }
}

void configurePerformance(conf::Performance &performance, str &text)
{

    str_cit start = text.begin();
    str_cit end = text.end();

    str_cit current = start;
    while (current < end)
    {
        Section sect = getNextSection(current, end);

        if (sect.name == "bpm")
        {
            performance.bpm = evaluate(sect.content.start, sect.content.end);
        }
        else if (sect.name == "scene")
        {
            performance.phrases.push_back(defaultPhrase);
            configurePhrase(performance.phrases.back(), sect.content.start, sect.content.end);
        }
        else
        {
            throw "Invalid scene configuration";
        }

        current = next(sect.content.end);
    }
}

void read(conf::Performance &performance, const str &filepath)
{
    std::ifstream ifs(filepath);

    str content((std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));

    strip(content);

    performance = defaultPerformance;
    
    configurePerformance(performance, content);
}