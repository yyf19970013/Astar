#include "Node.h"

 Node::Node(int x, int y, Node* parent):x_(x), y_(y), parent_(parent){}
 void Node::set_f(int f){f_ = f;}