#include <iostream>
#include <vector>
#include "Grid.h"
using namespace std;



int main(){
    unsigned rows, cols;
    rows = 5;
    cols = 5;
    Grid *g = new Grid(rows, cols);
    g->setPath();
    g->bfs();
    g->print();
    return 0;
}

