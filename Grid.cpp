#include "Grid.h"
#include <vector>
#include <iostream>
#include <tuple> //for tuple
#include <queue> 
#include <sstream>
#include <stack>
using namespace std;


//deconstructs the Grid
Grid::~Grid(){
    for (unsigned i = 0; i < grid.size(); ++i){
        for (unsigned j = 0; j < grid.at(i).size(); ++j){
            delete grid.at(i).at(j);
        }
    }
}
/*prints out the grid */
void Grid::print(){
    for (unsigned i = 0; i < grid.size(); ++i){
        for (unsigned j = 0; j < grid.at(i).size(); ++j){
            if (grid.at(i).at(j) != NULL){
                cout << "|" << grid.at(i).at(j)->get_distance();
            }
            else {
                cout << "|" << 0;
            }
        }
        cout << "|" << endl;
    }
}

/*performs breadth-first search
 *from the source until it finds
 *the target, setting the distance
 *of each cell along the way */
void Grid::bfs(){
    queue<tuple<int, int, int> > q; //stores the next grid cell that is to be visited and intialized
    q.push(make_tuple(source.second, source.first, 0)); //the tuple holds the vector index and the distance from the source
    grid.at(source.second).at(source.first) = new GridCell(get<2>(q.front()), 1);
    while (!q.empty()){
        if (get<0>(q.front()) == target.second && get<1>(q.front()) == target.first){
            break;
        }
        if (get<0>(q.front()) - 1 >= 0 && grid.at(get<0>(q.front()) - 1).at(get<1>(q.front())) == NULL){ //queues the top of the current cell
            q.push(make_tuple(get<0>(q.front()) - 1, get<1>(q.front()), get<2>(q.front()) + 1));
            grid.at(get<0>(q.front()) - 1).at(get<1>(q.front())) = new GridCell(get<2>(q.front()) + 1, 1);
        }
        if (get<0>(q.front()) + 1 != grid.size() && grid.at(get<0>(q.front()) + 1).at(get<1>(q.front())) == NULL){ //queues the bottom of the current cell
            q.push(make_tuple(get<0>(q.front()) + 1, get<1>(q.front()), get<2>(q.front()) + 1));
            grid.at(get<0>(q.front()) + 1).at(get<1>(q.front())) = new GridCell(get<2>(q.front()) + 1, 1);
        }
        if (get<1>(q.front()) - 1 >= 0 && grid.at(get<0>(q.front())).at(get<1>(q.front()) - 1) == NULL){ //queues the left of the current cell
            q.push(make_tuple(get<0>(q.front()), get<1>(q.front()) - 1, get<2>(q.front()) + 1));
            grid.at(get<0>(q.front())).at(get<1>(q.front()) - 1) = new GridCell(get<2>(q.front()) + 1, 1);
        }
        if (get<1>(q.front()) + 1 != grid.at(0).size() && grid.at(get<0>(q.front())).at(get<1>(q.front()) + 1) == NULL){ //queues the right of the current cell
            q.push(make_tuple(get<0>(q.front()), get<1>(q.front()) + 1, get<2>(q.front()) + 1));
            grid.at(get<0>(q.front())).at(get<1>(q.front()) + 1) = new GridCell(get<2>(q.front()) + 1, 1);
        }
        q.pop();
    }
}

/*gets the source and the target from the 
 *user */
void Grid::setPath(){ //TODO: Add checking the input
    int internalVec = grid.at(0).size();
    int externalVec = grid.size();
    int x, y;

    cout << "Enter the x value for source: ";
    x = getVal();
    while (x >= grid.at(0).size() || x < 0){
        cout << "Please enter the appropriate range: ";
        x = getVal();
    }
    cout << "Enter the y value for source: ";
    y = getVal();
    while (y >= grid.size() || y < 0){
        cout << "Please enter the appropriate range: ";
        y = getVal();
    }
    source = make_pair(x, y);

    cout << "Enter the x value for target: ";
    x = getVal();
    while (x >= grid.at(0).size() || x < 0){
        cout << "Please enter the appropriate range: ";
        x = getVal();
    }
    cout << "Enter the y value for target: ";
    y = getVal();
    while (y >= grid.size() || y < 0){
        cout << "Please enter the appropriate range: ";
        y = getVal();
    }
    target = make_pair(x, y);
}
/*searches for the path
 *if found, updates the Grid
 *else reports that there is no
 *path */
void Grid::findPath(){

}

//gets a value from a user
int getVal(){
    int x;
    string input;
    istringstream inSS;
    getline(cin, input);
    inSS.clear();
    inSS.str(input);
    inSS >> x;
    return x;
}