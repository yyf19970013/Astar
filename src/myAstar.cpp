#include "myAstar.h"

	Astar::Astar(vector<vector<int>> G, Node* S, Node* E):G_(G),S_(S),E_(E){}
	
	bool Astar::find_path(){

		auto cmp = [this](Node* a, Node* b){return a->f_ > b->f_;};

		unordered_set<Node*> close_list;
		priority_queue<Node*,vector<Node*>, decltype(cmp)> open_list(cmp);
		
		if(count == 0){
			open_list.push(S_);
			count++;
		}

		while(count != 0 && !open_list.empty()){
			auto curr = open_list.top();
			open_list.pop();
			close_list.insert(curr);
			
			if(curr->x_ == E_->x_ && curr->y_ == E_->y_){
				cout << "SUCCESS!" << endl;
				return true;
			} 

			for(int i = 0; i < 4; i++){
				Node* node;
				if(i == 0){
					int x = curr->x_ - 1;
					if(x < 0) continue;
					node = new Node(x, curr->y_, nullptr);
					if(close_list.find(node) != close_list.end())
						continue;
				}
				if(i == 1){
					int y = curr->y_ + 1;
					if(y > G_[0].size()) continue;
					node = new Node(curr->x_, y, nullptr);
					if(close_list.find(node) != close_list.end())
						continue;
				}
				if(i == 2){
					int x = curr->x_ + 1;
					if(x > G_.size()-1) continue;
					node = new Node(x, curr->y_, nullptr);
					if(close_list.find(node) != close_list.end())
						continue;
				}
				if(i == 3){
					int y = curr->y_ - 1;
					if(y < 0) continue;
					node = new Node(curr->x_, y, nullptr);
					if(close_list.find(node) != close_list.end())
						continue;
				}
				node->set_f(get_f_value(node));
				open_list.push(node);
			}
		}
		return false;

	}

	int Astar::get_f_value(Node* n){
		return G_[n->x_][n->y_] + abs(E_->x_ - n->x_) + abs(E_->y_ - n->y_);
	}


