//
// Created by Ilya on 14.11.2018.
//

#include "flowNetwork.h"
#include <utility>

FlowNetwork::FlowNetwork(int vertices, bool **edges, int (*capacity)(int, int), int source, int sink):
        Graph(vertices, edges), capacity(capacity), source(source), sink(sink) {}
