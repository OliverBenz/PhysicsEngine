#include "Tree.hpp"

namespace PhysEn {

Tree::~Tree(){
	if (first == nullptr)
		return;

	Node* previous;
	Node* node = first;
	while(node->next != nullptr) {
		previous = node;
		node = node->next;
		delete previous;
	}

	delete node;
}

std::ostream& operator<<(std::ostream& os, Tree& tree) {
	if(tree.first != nullptr) {
		os << "Tree: ";

		// Print all nodes
		Node* node = tree.first;
		while(node->next != nullptr){
			os << node->value << " ";
			node = node->next;
		}
		os << node->value << "\n";
	}
	else
		os << "Tree: Empty\n";

	return os;
}
void Tree::push_back(Node* node){
	if(first == nullptr)
		first = node;
	else
		last->next = node;
	last = node;
}

}
