#include "GridCell.h"
#include <iostream>
using namespace std;

GridCell::~GridCell(){}

GridCell::GridCell(int d, double weight){
    distance = d;
    this->weight = weight;
    visit = false;
}

int GridCell::get_distance(){
    return distance;
}

bool GridCell::get_visit(){
    return visit;
}

void GridCell::set_visit(bool b){
    visit = b;
}

/*this function is called when
 *a path is determined and this
 *GridCell is part of the path
 *so it turns the distance to 0
 *to signify its part of the path */
void GridCell::isPath(){ //not the most elaborate solution, but will do for the time being
    distance = 0;
}