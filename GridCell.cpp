#include "GridCell.h"
#include <iostream>
using namespace std;


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

GridCell::~GridCell(){
    cout << "GridCell Destructor called" << endl;
}