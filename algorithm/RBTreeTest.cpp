#include "RedBlackTree.h"

int main() {

	RedBlackTree<int> tree(0);

	tree.insert(3);
	tree.insert(3);
	tree.insert(5);
	tree.insert(1);
	tree.insert(7);
	tree.print();

	return 0;

}