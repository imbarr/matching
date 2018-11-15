//
// Created by Ilya on 15.11.2018.
//

#ifndef MATCHING_AUGMENTINGPATH_H
#define MATCHING_AUGMENTINGPATH_H


#include <vector>

class AugmentingPath {
public:
    std::vector<int> chain;
    int flow;
    AugmentingPath(int flow, std::vector<int> chain);
};


#endif //MATCHING_AUGMENTINGPATH_H
