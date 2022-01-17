#pragma once
#include <fstream>
#include <iostream>

struct array
{
	int* array;
	int pos;
};


template<class T>
struct TNode
{
	T key;
	TNode<T>* left, * right;
	TNode<T>(T x) :key(x), left(nullptr), right(nullptr)
	{};
};

template<class T>
class Tree
{
public:
	TNode<T>* root;
	Tree() : root(0) {};
	~Tree() { destroyTree(root); }
	void destroyTree(TNode<T>*& node);
	bool isEmpty(TNode<T>* root);
	T getRootData(TNode<T>* pNode);
	void setRootData(TNode<T>*& pNode, T elem);
	void attachLeftSon(TNode<T>* pNode, T elem);
	void attachRightSon(TNode<T>* pNode, T elem);
	void insert(TNode<T>*& root, T elem);
	void init();
	void init(T elem);
	void init(TNode<T>*& pNode, T elem);
	void attachLeftSubTree(TNode<T>* subTree);
	void attachRightSubTree(TNode<T>* subTree);
	void init(T elem, TNode<T>* leftTree, TNode<T>* rightTree);
	void remove(T elem);
	void deleteNode(TNode<T>*& pNode);
	T findSuccessor(TNode<T>*& pNode);
	void printNode(TNode<T>* pNode);
	TNode<T>* search(TNode<T>* root, T key);
	void preorderPrint(TNode<T>* root);
	TNode<T>* preorderCopy(TNode<T>* pNode, TNode<T>* root);
	void inorderPrint(TNode<T>* root);
	void printIfZero(TNode<T>* root);
	void postorderPrint(TNode<T>* root);
	void printMinSubTree(TNode<T>* root);
	T findMinSum(TNode<T>* root);
	T findMin(TNode<T>* root);
	int findNumberBranchers(TNode<T>* root);
	TNode<T> getNode(TNode<T>* root);
	int sizeTree(TNode<T>* root);
	int countNumberElem(TNode<T>* root, T elem, int& count);
	void copyTrees(Tree<T>*& arr, TNode<T>* root, T elem, int& c);
};