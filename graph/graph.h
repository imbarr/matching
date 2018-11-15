//
// Created by Ilya on 14.11.2018.
//

#ifndef MATCHING_MATRIX_H
#define MATCHING_MATRIX_H

#include <vector>
#include "edge.h"

class Graph {
public:
    int vertices;
    bool **edges;
    Graph(int vertices, bool **edges);
//    ~Graph();
};


#endif //MATCHING_MATRIX_H
