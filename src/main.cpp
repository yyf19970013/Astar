#include "myAstar.h"
#include "Node.h"


    int main(){
        vector<vector<int>> G{
            {1,1,1},
            {1,1,1},
            {1,1,1}
        };
        Node* start = new Node(0,0,nullptr);
        Node* end = new Node(2,2,nullptr);
        Astar A(G, start, end);
        A.find_path();
        return 0;
    }

