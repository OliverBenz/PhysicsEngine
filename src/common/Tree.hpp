#pragma once

#include <iostream>

namespace PhysEn {

struct Node {
	std::string value;
	// Node* parent = nullptr;
	Node* next = nullptr;
};

struct Tree {
	Node* first = nullptr;
	Node* last  = nullptr;

	~Tree();

	// Member functions
	void push_back(Node* node);

	friend std::ostream& operator<<(std::ostream& os, Tree& tree);
};

}
