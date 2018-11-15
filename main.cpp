#include <iostream>
#include <fstream>
#include "util.h"
#include "algorithm.h"

int main() {
    std::ifstream input;
    input.open("input.txt");
    auto graph = fromInput(input);
    auto result = maximumMatching(graph);
    std::ofstream output;
    output.open("output.txt");
    toOutput(output, result);
}