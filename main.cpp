#include <iostream>
#include <vector>
#include "Grid.h"
#include <unistd.h>
using namespace std;



int main(){
    while(true){
        int rows, cols;
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
        sleep(30);
        delete g;
        cout << endl;
    }
    return 0;
}

