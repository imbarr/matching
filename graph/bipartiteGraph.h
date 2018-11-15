//
// Created by Ilya on 14.11.2018.
//

#ifndef MATCHING_BIPARTITEGRAPH_H
#define MATCHING_BIPARTITEGRAPH_H


#include <fstream>
#include "graph.h"

class BipartiteGraph: public Graph {
public:
    int secondSet;
    BipartiteGraph(int vertices, int secondSet, bool **edges);
};


#endif //MATCHING_BIPARTITEGRAPH_H
