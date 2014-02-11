#include <iostream>
#include "list.h"

List::List() : first(nullptr), list_size(0) {
}

List::~List() {
  Node* n = first;
  int i = 0;
  while(n != nullptr){
      Node* del = n;
      n = n->next;
      delete del;
      ++i;
  }
}

bool List::exists(int d) const {
	int i=0;
	Node* n = first;
	while(n != nullptr){
		if(d == n->value){
			return true;
		}
		n = n->next;
		i++;
	}
	return false;
}

int List::size() const {
	return list_size;
}

bool List::empty() const {
	return list_size == 0;
}

void List::insertFirst(int d) {
	Node* node;
	if(first){
		node = new Node(d, first);
	}else{
		node = new Node(d, nullptr);
	}
	first = node;
	++list_size;
}

void List::remove(int d, DeleteFlag df) {
	Node* n = first;
	Node* p = nullptr;
	int i = 0;
	int prev_size = size();
	while(i < prev_size){
		if((df == DeleteFlag::EQUAL && n->value == d) ||
			(df == DeleteFlag::LESS && n->value < d) || 
			(df == DeleteFlag::GREATER && n->value > d)){
			if(p != nullptr){
				p->next = n->next;
			}else{
				first = nullptr;
			}
			Node* del = n;
			n = n->next;
			delete del;
			--list_size;
		}else{
		  p = n;
		  n = n->next;
		}
		++i;
	}
}

void List::print() const {
	Node* n = first;
	if(this->empty()){
		return;
	}

	int i = 0;
	while(i < size()){
		std::cout << n->value << ", " << std::endl;
		n = n->next;
		i++;
	}
}

