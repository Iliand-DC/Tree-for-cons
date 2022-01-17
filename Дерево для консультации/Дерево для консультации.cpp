#include "SearchTree.h"
#include "SearchTree.cpp"
#include <fstream>



int main()
{
	setlocale(LC_ALL, "rus");
	std::ifstream in("input.txt");
	Tree<int> tree;
	while (!in.eof())
	{
		int h;
		in >> h;
		tree.insert(tree.root, h);
	}
	tree.preorderPrint(tree.root);
	std::cout << '\n';
	int count = 0;
	int size = tree.countNumberElem(tree.root, 0, count);
	Tree<int>* arr = new Tree<int>[size];
	int c = 0;
	tree.copyTrees(arr, tree.root, 0, c);

	for (int i = 0; i < size; i++)
	{
		tree.preorderPrint(arr[i].root);
		std::cout << '\n';
	}
}

