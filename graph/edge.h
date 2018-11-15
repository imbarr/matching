//
// Created by Ilya on 14.11.2018.
//

#ifndef MATCHING_EDGE_H
#define MATCHING_EDGE_H


class Edge {
public:
    Edge(int from, int to);
    const int from, to;

    bool operator< (const Edge&) const;
};


#endif //MATCHING_EDGE_H
