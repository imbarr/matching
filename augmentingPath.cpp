//
// Created by Ilya on 15.11.2018.
//

#include "augmentingPath.h"
#include <utility>

AugmentingPath::AugmentingPath(int flow, std::vector<int> chain): flow(flow), chain(std::move(chain)) {}
