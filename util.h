//
// Created by Ilya on 14.11.2018.
//

#ifndef MATCHING_UTIL_H
#define MATCHING_UTIL_H

#include <fstream>
#include "graph/bipartiteGraph.h"

BipartiteGraph fromInput(std::ifstream &input);

void toOutput(std::ofstream &output, BipartiteGraph matching);

#endif //MATCHING_UTIL_H
