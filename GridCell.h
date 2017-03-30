#ifndef GRIDCELL_HH
#define GRIDCELL_HH
#include <iostream>
using namespace std;

/*a class that represents
  a cell within a grid */
class GridCell{
    private:
        int distance; //holds the distance from the source
        double weight; //weight of the cell
        bool visit; //true if it has been traversed through
    public:
        ~GridCell();
        GridCell(int d, double weight);
        int get_distance();
        bool get_visit();
        void set_visit(bool b);
};

#endif