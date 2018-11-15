//
// Created by Ilya on 14.11.2018.
//

#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include "algorithm.h"
#include "augmentingPath.h"

FlowNetwork toFlowNetwork(BipartiteGraph graph) {
    auto edges = new bool*[graph.vertices + 2];
    for (int i = 0; i < graph.vertices + 2; ++i) {
        edges[i] = new bool[graph.vertices + 2];
        std::fill_n(edges[i], graph.vertices + 2, false);
    }
    for (int i = 0; i < graph.vertices; ++i) {
        for (int j = 0; j < graph.vertices; ++j)
            edges[i][j] = graph.edges[i][j];
    }
    for (int i = 0; i < graph.secondSet; ++i)
        edges[graph.vertices][i] = true;
    for (int i = graph.secondSet; i < graph.vertices; ++i)
        edges[i][graph.vertices + 1] = true;
    return {graph.vertices + 2, edges, [](int from, int to) -> int {return 1;}, graph.vertices, graph.vertices + 1};
}

AugmentingPath* augmentingPath(FlowNetwork network, std::map<Edge, int> flow) {
    auto parent = new int[network.vertices];
    std::fill_n(parent, network.vertices, -1);
    auto old = new bool[network.vertices];
    std::fill_n(old, network.vertices, false);
    auto current = std::queue<int>();
    current.push(network.source);
    old[network.source] = true;

    while (!current.empty()) {
        int c = current.front();
        current.pop();
        for (int i = 0; i < network.vertices; ++i) {
            bool forward = network.edges[c][i] && (flow[Edge(c, i)] < network.capacity(c, i));
            bool backward = network.edges[i][c] && (flow[Edge(i, c)] > 0);
            if((forward || backward) && !old[i]) {
                current.push(i);
                old[i] = true;
                parent[i] = c;
            }
        }
    }

    if(parent[network.sink] == -1)
        return nullptr;
    int c = network.sink;
    auto path = std::vector<int>();
    auto maxFlow = INT_MAX;
    while(c != network.source) {
        path.push_back(c);
        maxFlow = network.edges[parent[c]][c]
                  ? std::min(maxFlow, network.capacity(parent[c], c) - flow[Edge(parent[c], c)])
                  : std::min(maxFlow, flow[Edge(c, parent[c])]);
        c = parent[c];
    }
    path.push_back(c);
    std::reverse(path.begin(), path.end());
    return new AugmentingPath(maxFlow, path);
}

std::map<Edge, int> fordFulkerson(FlowNetwork network) {
    auto flow = std::map<Edge, int>();
    for (int i = 0; i < network.vertices; ++i)
        for (int j = 0; j < network.vertices; ++j)
            if(network.edges[i][j]) {
                flow[Edge(i, j)] = 0;
            }

    while (auto path = augmentingPath(network, flow)) {
        int prev = network.source;
        for (auto i = std::next(path->chain.begin()); i < path->chain.end(); ++i) {
            if(network.edges[prev][*i])
                flow[Edge(prev, *i)] += path->flow;
            else
                flow[Edge(*i, prev)] -= path->flow;
            prev = *i;
        }
    }
    return flow;
}

BipartiteGraph maximumMatching(BipartiteGraph graph) {
    auto network  = toFlowNetwork(graph);
    auto flow = fordFulkerson(network);
    auto edges = new bool*[graph.vertices];
    for (int i = 0; i < graph.vertices; ++i) {
        edges[i] = new bool[graph.vertices];
        std::fill_n(edges[i], graph.vertices, false);
    }
    for (auto pair : flow)
        if(pair.first.from != network.source && pair.first.to != network.sink && pair.second == 1)
            edges[pair.first.from][pair.first.to] = true;
    return {graph.vertices, graph.secondSet, edges};
}