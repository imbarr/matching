//
// Created by Ilya on 14.11.2018.
//

#include <vector>
#include "util.h"

BipartiteGraph fromInput(std::ifstream &input) {
    int x, y;
    input >> x;
    input >> y;
    auto edges = new bool*[x + y];
    for (int i = 0; i < x + y; ++i) {
        edges[i] = new bool[x + y];
        std::fill_n(edges[i], x + y, false);
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            int t;
            input >> t;
            edges[i][x + j] = (t == 1);
        }
    }
    return {x + y, x, edges};
}

void toOutput(std::ofstream &output, BipartiteGraph matching) {
    for (int i = 0; i < matching.secondSet; ++i) {
        int out = 0;
        for (int j = matching.secondSet; j < matching.vertices; ++j)
            if(matching.edges[i][j])
                out = j - matching.secondSet + 1;
        output << out << " ";
    }
}
