#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_set>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
    public:
        int x_;
        int y_;
        int f_;
        Node* parent_ = nullptr;

        Node(int x, int y, Node* parent);
		~Node() = default;
        void set_f(int f);
};

#endif