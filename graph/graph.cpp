//
// Created by Ilya on 14.11.2018.
//

#include "graph.h"
#include <utility>

Graph::Graph(int vertices, bool **edges): vertices(vertices), edges(edges) {}

//Graph::~Graph() {
//    for (int i = 0; i < vertices; ++i)
//        delete[] edges[i];
//    delete[] edges;
//}


