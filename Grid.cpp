#include "Grid.h"
#include <vector>
#include <iostream>
#include <tuple> //for tuple
#include <queue> 
#include <sstream>
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
    vector<tuple<int, int, int> > v;
    queue<tuple<int, int, int> > q; //stores the next grid cell that is to be visited and intialized
    q.push(make_tuple(0, 0, 0)); //the tuple holds the vector index and the distance from the source
    while (!q.empty()){
        v.push_back(q.front());
        // cout << get<0>(q.front()) << " " << get<1>(q.front()) << " " << get<2>(q.front()) << endl;
        if (get<0>(q.front()) == 49 && get<1>(q.front()) == 49){
            grid.at(get<0>(q.front())).at(get<1>(q.front())) = new GridCell(get<2>(q.front()), 0);
            break;
        }
        if (grid.at(get<0>(q.front())).at(get<1>(q.front())) == NULL){
            grid.at(get<0>(q.front())).at(get<1>(q.front())) = new GridCell(get<2>(q.front()), 0);
        }
        if (get<0>(q.front()) - 1 >= 0 && grid.at(get<0>(q.front()) - 1).at(get<1>(q.front())) == NULL){ //queues the top of the current cell
            q.push(make_tuple(get<0>(q.front()) - 1, get<1>(q.front()), get<2>(q.front()) + 1));
        }
        if (get<0>(q.front()) + 1 != grid.at(0).size() && grid.at(get<0>(q.front()) + 1).at(get<1>(q.front())) == NULL){ //queues the bottom of the current cell
            q.push(make_tuple(get<0>(q.front()) + 1, get<1>(q.front()), get<2>(q.front()) + 1));
        }
        if (get<1>(q.front()) - 1 >= 0 && grid.at(get<0>(q.front())).at(get<1>(q.front()) - 1) == NULL){ //queues the left of the current cell
            q.push(make_tuple(get<0>(q.front()), get<1>(q.front()) - 1, get<2>(q.front()) + 1));
        }
        if (get<1>(q.front()) + 1 != grid.at(0).size() && grid.at(get<0>(q.front())).at(get<1>(q.front()) + 1) == NULL){ //queues the right of the current cell
            q.push(make_tuple(get<0>(q.front()), get<1>(q.front()) + 1, get<2>(q.front()) + 1));
        }
        q.pop();
    }
    cout << v.size() << endl;
}
/*gets the source and the target from the 
 *user */
void Grid::setPath(){ //TODO: Add checking the input ability
    int internalVec = grid.at(0).size();
    int externalVec = grid.size();
    int x, y;
    string input;
    stringstream SS;
    cout << "Enter the x value for source: ";
    getline(cin, input);
    SS << input;
    SS >> x;

    cout << "Enter the y value for source: ";
    getline(cin, input);
    SS << input;
    SS >> y;

    source = make_pair(x, y);

    cout << "Enter the x value for target: ";
    getline(cin, input);
    SS << input;
    SS >> x;

    cout << "Enter the y value for target: ";
    getline(cin, input);
    SS << input;
    SS >> y;

    target = make_pair(x, y);


}