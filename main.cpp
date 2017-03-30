#include <iostream>
#include <vector>
#include "Grid.h"
using namespace std;



int main(){
    int rows, cols;
    while(true){
        cout << "Enter number of rows(negative number or zero to quit): ";
        rows = getVal();
        if (rows <= 0){
            break;
        }
        cout << "Enter number of columns(negative number or zero to quit): ";
        cols = getVal();
        if (cols <= 0){
            break;
        }
        Grid *g = new Grid(rows, cols);
        g->setPath();
        g->bfs();
        g->print();
        g->findPath();
        cout << endl;
    }
    return 0;
}

