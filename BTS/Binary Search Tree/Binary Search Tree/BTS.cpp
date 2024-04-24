#include "BTS.h"
#include <iostream>
#include <queue>

BTS::BTS()
	: root{nullptr},
	_size{0}
{}

void BTS::insert(int value) {
	node* ptr = new node{ value };
	if (!root) {
		root = ptr;
	} else {
		node* temp = root, *prev = nullptr;;
		while (temp) {
			prev = temp;
			temp = value < temp->value ? temp->left : temp->right;
		}

		if (value < prev->value) {
			prev->left = ptr;
		}
		else {
			prev->right = ptr;
		}
	}
	++_size;
}

void BTS::remove(int value) {
	if (!root) {
		throw BTSException{ "tree is empty. " };
	}
	node* ptr = root, *prev = nullptr;
	while (ptr) {
		if (ptr->value == value) {
			break;
		}
		prev = ptr;
		ptr = value < ptr->value ? ptr = ptr->left : ptr = ptr->right;
	}
	if (ptr == nullptr) {
		throw BTSException{ "binary tree doesn't have that value" };
	}

	if (ptr->right && ptr->left) { // 2 child
		node* temp = ptr->right, *prev = nullptr;
		while (temp->left) {
			prev = temp;
			temp = temp->left;
		}
		ptr->value = temp->value;
		if (prev) {
			prev->left = temp->right;
		}
		delete temp;
	}
	else if (ptr->right) { // 1 child
		if (prev == nullptr) {
			root = ptr->right;
		} 
		else if (prev->left == ptr) {
			prev->left = ptr->right;
		}
		else {
			prev->right = ptr->right;
		}
		delete ptr;
	}
	else if (ptr->left) { // 1 child
		if (prev == nullptr) {
			root = ptr->left;
		} 
		else if (prev->left == ptr) {
			prev->left = ptr->left;
		}
		else {
			prev->right = ptr->left;
		}
		delete ptr;
	}
	else { // leaf node
		delete ptr;
	}
	--_size;
}

void BTS::levelorderT(node* root)
{
	if (!root) {
		return;
	}
	std::queue<node*> q;
	q.push(root);
	q.push(nullptr);
	while (q.size() != 1) {
		if (q.front() == nullptr) {
			q.pop();
			std::cout << std::endl;
			q.push(nullptr);
		}
		if (q.front()->left) {
			q.push(q.front()->left);
		}
		if (q.front()->right) {
			q.push(q.front()->right);
		}
		std::cout << q.front()->value << ' ';
		q.pop();
	}
}

bool BTS::find(int value) const
{
	if (!root) {
		return false;
	}
	node* ptr = root;
	while (ptr) {
		if (ptr->value == value) {
			break;
		}
		ptr = value < ptr->value ? ptr->left : ptr->right;
	}
	if (ptr) {
		return true;
	}

	return false;
}

node* BTS::getRoot() const
{
	return root;
}

int BTS::getSize() const
{
	return _size;;
}
