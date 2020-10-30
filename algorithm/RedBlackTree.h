#pragma once

#include <queue>
#include <string>
#include <iostream>

enum RBColor {
	RB_RED,
	RB_BLACK
};

template <typename T> class RedBlackTreeNode{

	template <typename T> friend class RedBlackTree;
	RBColor color;
	RedBlackTreeNode<T>* parent;
	RedBlackTreeNode<T>* left;
	RedBlackTreeNode<T>* right;
	T data;

	RedBlackTreeNode(T data, RedBlackTreeNode<T>* nilNode) {
		this->color = RB_RED;
		this->data = data;
		if (nilNode != nullptr) {
			this->left = nilNode;
			this->right = nilNode;
		}
		else {
			this->left = this;
			this->right = this;
		}
		this->parent = nullptr;

	}

	void print(std::string indent, bool last = true) {
		std::cout << indent;
		std::cout << (last ? "¦±¦¬ " : "¦¬ ") << this->data << " color : " << this->color << std::endl;
		if (right != this) {
			right->print(indent + "  ¦­", false);
		}
		if (left != this) {
			left->print(indent + "  ", true);
		}
	}

};

template<typename T> class RedBlackTree
{

	RedBlackTreeNode<T>* root;
	RedBlackTreeNode<T>* nilNode;

public:

	RedBlackTree(T nilData) {
		this->nilNode = new RedBlackTreeNode<T>(nilData, nullptr);
		this->nilNode->color = RB_BLACK;
		this->root = this->nilNode;
	}

	void insert(T data) {
		if (root == nilNode) {
			this->root = new RedBlackTreeNode<T>(data, nilNode);
			this->root->color = RB_BLACK;
		}
		else {
			RedBlackTreeNode<T>* p = nullptr;
			RedBlackTreeNode<T>* temp = root;
			while (temp != nilNode) {
				p = temp;
				temp = nilNode;
				if (p->data == data) {
					std::cout << "warning : trying to insert existing data " << data << std::endl;
					return;
				}
				else if (p->data > data) {
					temp = p->left;
				}
				else {
					temp = p->right;
				}
			}
			if (p->data > data) {
				p->left = new RedBlackTreeNode<T>(data, nilNode);
				p->left->parent = p;
			}
			else {
				p->right = new RedBlackTreeNode<T>(data, nilNode);
				p->right->parent = p;
			}
		}
	}

	void print() {

		root->print("");

	}

};