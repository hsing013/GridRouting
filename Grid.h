#ifndef GRID_HH
#define GRID_HH
#include "GridCell.h"
#include <iostream>
#include <vector>
using namespace std;

/*represents a whole grid
 *made up of GridCells */
class Grid{
    private:
        vector<vector<GridCell*> >grid;
        pair<int, int> source;
        pair<int, int> target;
    public:
        Grid() {};
        ~Grid();
        Grid(unsigned rows, unsigned cols) : grid(rows, vector<GridCell*>(cols, NULL)) {};
        void setPath();
        void print();
        void bfs();
};

#endif