#include <iostream>
#include <vector>
#include "Grid.h"
using namespace std;



int main(){
    unsigned rows, cols;
    rows = 20;
    cols = 20;
    Grid *g = new Grid(rows, cols);
    g->bfs();
    g->setPath();
    g->print();
    return 0;
}

