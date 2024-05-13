#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include "Node.h"
using namespace std;

    class Astar{
    public:
        Astar(vector<vector<int>> G, Node* Start, Node* End);
        ~Astar() = default;
        int get_f_value(Node* n);
        bool find_path();

    private:
        vector<Node> path_;
        const vector<vector<int>> G_;
        Node* S_;
        Node* E_;
        int count = 0;
    };
