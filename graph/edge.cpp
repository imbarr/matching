//
// Created by Ilya on 14.11.2018.
//

#include "edge.h"

Edge::Edge(int from, int to): from(from), to(to) {}

bool Edge::operator<(const Edge &other) const {
    return this->from < other.from || (this->from == other.from && this->to < other.to);
}
