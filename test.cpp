#include <iostream>
#include "GridCell.h"
#include <vector>
using namespace std;

int main(){
    
    vector<GridCell*> v(10, NULL);
    if (v.at(0) == NULL){
        cout << "Hello" << endl;
    }
    // for (unsigned i = 0; i < v.size(); ++i){
    //     v.at(i) = new GridCell();
    // }
    // fill(v.begin(), v.end(), NULL);
    
}