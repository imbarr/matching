//
// Created by Ilya on 14.11.2018.
//

#include <utility>
#include "bipartiteGraph.h"

BipartiteGraph::BipartiteGraph(int vertices, int secondSet, bool **edges):
        Graph(vertices, edges), secondSet(secondSet) {}