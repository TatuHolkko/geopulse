#include "cluster.h"

Cluster::Cluster(conf::Cluster conf, Timer &t)
{

    //create sequence of sequences (one sequence per shape) for each vertex property

    Sequence<conf::Sequence<conf::FunctionParameters>> angleSeqSeq = Sequence<conf::Sequence<conf::FunctionParameters>>(conf.angle.paramSequenceSequence.base,
                                                                   conf.angle.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> radiusSeqSeq = Sequence<conf::Sequence<conf::FunctionParameters>>(conf.radius.paramSequenceSequence.base,
                                                                   conf.radius.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> redSeqSeq = Sequence<conf::Sequence<conf::FunctionParameters>>(conf.red.paramSequenceSequence.base,
                                                                   conf.red.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> greenSeqSeq = Sequence<conf::Sequence<conf::FunctionParameters>>(conf.green.paramSequenceSequence.base,
                                                                   conf.green.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> blueSeqSeq = Sequence<conf::Sequence<conf::FunctionParameters>>(conf.blue.paramSequenceSequence.base,
                                                                   conf.blue.paramSequenceSequence.delta);

    for (int i = 0; i < conf.amount; i++)
    {
        auto temp = radiusSeqSeq.next();
        shapes.push_back(Shape(
            conf.vertices,
            {
                .type = conf.angle.type,
                .paramSequence = angleSeqSeq.next(),
            },
            {
                .type = conf.radius.type,
                .paramSequence = temp,
            },
            {
                .type = conf.red.type,
                .paramSequence = redSeqSeq.next(),
            },
            {
                .type = conf.green.type,
                .paramSequence = greenSeqSeq.next(),
            },
            {
                .type = conf.blue.type,
                .paramSequence = blueSeqSeq.next(),
            },
            t));
    }
}

void Cluster::draw() const
{
    for (const Shape &shape : shapes)
    {
        shape.draw();
    }
}