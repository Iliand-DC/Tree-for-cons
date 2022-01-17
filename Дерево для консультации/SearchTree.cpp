#include "SearchTree.h"

template<class T>
void Tree<T>::destroyTree(TNode<T>*& node)
{
	if (node)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
		node = nullptr;
	}
}

template<class T>
bool Tree<T>::isEmpty(TNode<T>* pNode)
{
	return pNode == nullptr;
}

template<class T>
T Tree<T>::getRootData(TNode<T>* pNode)
{
	if (!isEmpty(root))
		return root->key;
	else
		std::cout << "Пусто.\n";
}

template<class T>
void Tree<T>::init()
{
	root = nullptr;
}

template <class T>
void Tree<T>::init(TNode<T>*& pNode, T elem)
{
	root = new TNode<T>(0);
	root->key = elem;
	root->left = nullptr;
	root->right = nullptr;
}

template<class T>
void Tree<T>::setRootData(TNode<T>*& pNode, T elem)
{
	if (!isEmpty(pNode))
		pNode->data = elem;
	else
		init(pNode, elem);
}

template<class T>
void Tree<T>::init(T elem)
{
	root = new TNode<T>(0);
	root->key = elem;
	root->left = nullptr;
	root->right = nullptr;
}

template<class T>
void Tree<T>::attachLeftSon(TNode<T>* pNode, T elem)
{
	if (isEmpty(root))
		std::cout << "Пусто.\n";
	else
		if (root->left != nullptr)
			std::cout << "Поддерево не пусто.\n";
		else
		{
			TNode<T>* p = new TNode<T>(0);
			p->key = elem;
			p->left = nullptr;
			p->right = nullptr;
			pNode->left = p;
		}
}

template<class T>
void Tree<T>::attachRightSon(TNode<T>* pNode, T elem)
{
	if (isEmpty(root))
		std::cout << "Пусто.\n";
	else
		if (root->right != nullptr)
			std::cout << "Поддерево не пусто.\n";
		else
		{
			TNode<T>* p = new TNode<T>(0);
			p->key = elem;
			p->left = nullptr;
			p->right = nullptr;
			pNode->right = p;
		}
}

template<class T>
void Tree<T>::insert(TNode<T>*& pNode, T elem)
{
	if (isEmpty(pNode))
		pNode = new TNode<T>(elem);
	else
		if (elem < pNode->key)
			insert(pNode->left, elem);
		else insert(pNode->right, elem);

}

template<class T>
void Tree<T>::attachLeftSubTree(TNode<T>* subTree)
{
	if (root == nullptr) std::cout << "Дерево пусто.\n";
	else if (!(root == nullptr))
	{
		if (root->left != nullptr)
			std::cout << "Поддерево не пусто.\n";
		root->left = subTree;
	}
}

template<class T>
void Tree<T>::attachRightSubTree(TNode<T>* subTree)
{
	if (root == nullptr) std::cout << "Дерево пусто.\n";
	else if (!(root == nullptr))
	{
		if (root->right != nullptr)
			std::cout << "Поддерево не пусто.\n";
		root->right = subTree;
	}
}

template<class T>
void Tree<T>::init(T elem, TNode<T>* leftTree, TNode<T>* rightTree)
{
	init(elem);
	attachLeftSubTree(root, leftTree);
	attachRightSubTree(root, rightTree);
}

template<class T>
T Tree<T>::findSuccessor(TNode<T>*& pNode)
{
	if (pNode->left == nullptr)
	{
		T elem = pNode->key;
		TNode<T>* delNode = pNode;
		pNode = pNode->right;
		delete delNode;
		return elem;
	}
	else findSuccessor(pNode->left);
}

template<class T>
void Tree<T>::printNode(TNode<T>* pNode)
{
	std::cout << pNode->key <<  ':';
}

template<class T>
TNode<T> Tree<T>::getNode(TNode<T>* tree)
{
	return tree;
}

template<class T>
TNode<T>* Tree<T>::search(TNode<T>* pNode, T key)
{
	if (isEmpty(pNode)) return 0;
	else if (key == pNode->key) return pNode;
	else if (key < pNode->key) return search(pNode->left, key);
	else return search(pNode->right, key);
}


template<class T>
void Tree<T>::preorderPrint(TNode<T>* pNode)
{
	if (!(pNode == nullptr))
	{
		printNode(pNode);
		preorderPrint(pNode->left);
		preorderPrint(pNode->right);
	}
}

template<class T>
TNode<T>* Tree<T>::preorderCopy(TNode<T>* pNode, TNode<T>* root)
{
	if (!(pNode == nullptr))
	{
		root = pNode;
		preorderCopy(pNode->left, root->left);
		preorderCopy(pNode->right, root->right);
	}
	return root;
}

template<class T>
void Tree<T>::inorderPrint(TNode<T>* root)
{
	if (root != nullptr)
	{
		inorderPrint(root->left);
		printNode(root);
		inorderPrint(root->right);
	}
}

template<class T>
void Tree<T>::postorderPrint(TNode<T>* root)
{
	if (root != nullptr)
	{
		postorderPrint(root->left);
		postorderPrint(root->right);
		printNode(root);
	}
}

template<class T>
void Tree<T>::deleteNode(TNode<T>*& pNode)
{
	if (pNode->left == nullptr && pNode->right == nullptr)
	{
		delete pNode;
		pNode = nullptr;
	}
	else
	{
		TNode<T>* delNode;
		if (pNode->left == nullptr || pNode->right == nullptr)
		{
			delNode = pNode;
			if (pNode->left == nullptr)
				pNode = pNode->right;
			else pNode = pNode->left;
			delete delNode;
			delNode = nullptr;
		}
		else pNode->key = findSuccessor(pNode->right);
	}
}

template<class T>
void Tree<T>::remove(T elem)
{
	if (!isEmpty(root))
		if (elem == root->key)
			deleteNode(root);
		else if (elem < root->key)
			remove(root->left, elem);
		else remove(root->right, elem);
}

template<class T>
T Tree<T>::findMinSum(TNode<T>* root)
{
	if (root != nullptr)
	{
		T min = 0;
		if (root->left == nullptr && root->right != nullptr)
		{
			min = root->key + findMinSum(root->right);
		}
		else if (root->right == nullptr && root->left != nullptr)
		{
			min = root->key + findMinSum(root->left);
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			min = root->key;
			T temp1 = findMinSum(root->left);
			T temp2 = findMinSum(root->right);
			if (temp1 < temp2)
				min += temp1;
			else if (temp1 > temp2)
				min += temp2;
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			min += root->key;
		}
		return min;
	}
	else return 0;
}

template<class T>
T Tree<T>::findMin(TNode<T>* root)
{
	if (root != nullptr)
	{
		T min = root->key;
		if (root->left == nullptr && root->right != nullptr)
		{
			min = findMin(root->right);
		}
		else if (root->right == nullptr && root->left != nullptr)
		{
			min = findMin(root->left);
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			min = root->key;
			T temp1 = findMin(root->left);
			T temp2 = findMin(root->right);
			if (temp1 < temp2)
			{
				min = temp1;
			}
			else if (temp1 > temp2)
			{
				min = temp2;
			}
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			if (min > root->key)
				min = root->key;
		}
		return min;
	}
	else return 0;
}



template<class T>
int Tree<T>::findNumberBranchers(TNode<T>* root)
{
	if (root == nullptr) return 0;
	else if (root != nullptr)
	{
		int sum = 0;
		sum += findNumberBranchers(root->left);
		sum += findNumberBranchers(root->right);
		if (root->left == nullptr && root->right == nullptr)
			sum++;
		return sum;
	}
}

template<class T>
int Tree<T>::sizeTree(TNode<T>* root)
{
	int size = 0;
	if (root != nullptr)
	{
		size++;
		size += sizeTree(root->left);
		size += sizeTree(root->right);
	}
	else return size;
}


template<class T>
int Tree<T>::countNumberElem(TNode<T>* root, T elem, int &count)
{
	if (root != nullptr)
	{
		if (root->key == elem)
			count++;
		countNumberElem(root->left, elem, count);
		countNumberElem(root->right, elem, count);
	}
	return count;
}

template<class T>
void Tree<T>::copyTrees(Tree<T>*& arr, TNode<T>* root, T elem, int& c)
{
	if (root != nullptr)
	{
		if (root->key == 0)
		{
			arr[c].root = root;
			c++;
		}
		copyTrees(arr, root->left, 0, c);
		copyTrees(arr, root->right, 0, c);
	}
}

template<class T>
void Tree<T>::printMinSubTree(TNode<T>* root)
{
	if (root != nullptr)
	{
		printNode(root);
		printMinSubTree(root->left);
		if (root->left == nullptr && root->right != nullptr)
			printMinSubTree(root->right);
	}
}
template<class T>
void Tree<T>::printIfZero(TNode<T>* root)
{
	if (root != nullptr)
	{
		if (root->key == 0)
		{
			preorderPrint(root);
		}
		printIfZero(root->left);
		printIfZero(root->right);
	}
}
