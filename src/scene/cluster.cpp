#include "cluster.h"

Cluster::Cluster(conf::Cluster conf, Timer &t)
{

    //create sequence of sequences (one sequence per shape) for each vertex property

    Sequence<conf::Sequence<conf::FunctionParameters>> angleSeqSeq(conf.angle.paramSequenceSequence.base,
                                                                   conf.angle.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> radiusSeqSeq(conf.radius.paramSequenceSequence.base,
                                                                    conf.radius.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> redSeqSeq(conf.red.paramSequenceSequence.base,
                                                                 conf.red.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> greenSeqSeq(conf.green.paramSequenceSequence.base,
                                                                   conf.green.paramSequenceSequence.delta);

    Sequence<conf::Sequence<conf::FunctionParameters>> blueSeqSeq(conf.blue.paramSequenceSequence.base,
                                                                  conf.blue.paramSequenceSequence.delta);

    for (int i = 0; i < conf.amount; i++)
    {
        auto temp = radiusSeqSeq.next();
        shapes.push_back(Shape(
            conf.vertices,
            {
                .type = conf.angle.type,
                .dVertexSymmetry = conf.angle.dVertexSymmetry,
                .paramSequence = angleSeqSeq.next(),
            },
            {
                .type = conf.radius.type,
                .dVertexSymmetry = conf.radius.dVertexSymmetry,
                .paramSequence = temp,
            },
            {
                .type = conf.red.type,
                .dVertexSymmetry = conf.red.dVertexSymmetry,
                .paramSequence = redSeqSeq.next(),
            },
            {
                .type = conf.green.type,
                .dVertexSymmetry = conf.green.dVertexSymmetry,
                .paramSequence = greenSeqSeq.next(),
            },
            {
                .type = conf.blue.type,
                .dVertexSymmetry = conf.blue.dVertexSymmetry,
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