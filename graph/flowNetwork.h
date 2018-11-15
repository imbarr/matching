//
// Created by Ilya on 14.11.2018.
//

#ifndef MATCHING_FLOWNETWORK_H
#define MATCHING_FLOWNETWORK_H


#include "graph.h"
#include <map>

class FlowNetwork: public Graph {
public:
    int source, sink, (*capacity)(int, int);
    FlowNetwork(int vertices, bool **edges, int (*capacity)(int, int), int source, int sink);
};

#endif //MATCHING_FLOWNETWORK_H
