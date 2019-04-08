#include <iostream>
#include <string>
#include"pch.h"
using namespace std;
template <class T>
class Tree {
	 struct Node {
		T item;
		Node *left;
		Node *right;
		Node *parent;
		int childs;
		Node(T i, Node *parent = nullptr, Node *l = nullptr, Node *r = nullptr) {
			item = i;
			left = l;
			right = r;
			childs = 0;
		}

	};
	Node *root;
	Node *y;
	int cnt=0;
	int arr[100];
	int index=0;
	int max = 0;
public:
	Tree()
	{
		root = nullptr;
		y = nullptr;
	}
	~Tree()
	{
		DeleteSubTree(root);
	}
	int GetHeight()
	{
		return GetHeight(root);
	}
	bool IsIsomorf( Tree t2)
	{
		return isIsomorphic(root, t2.root);
	}
	int IsSame( Tree t2)
	{
		if (index != t2.index)
		{
			std::cout << "Not Same";
			return 0;
		}
		bool t = true;
		for (int i = 0; i < index; i++)
		{
			if (arr[i] != t2.arr[i])
				t = false;
		}
		if(!t)
			std::cout << "Not Same";
		else
			std::cout << "Same";

		
	}
	int GetNodes(int level)
	{
		return GetNodes(root,level);
	}
	void Add(const T & element)
	{
		Add(root, element);
	}
	void AddF(const T & element)
	{
		AddF(root, element);
	}
	void print( )
	{
		print_Tree(root);
	}
	int GetLeaves()
	{
		return getLeafCount(root);
	}


private:
	void Add(Node *&node, const T &element);
	void AddF(Node *&node, const T &element);


	bool isIsomorphic(Node* n1, Node *n2);
	void DeleteSubTree(Node*node);
	int GetHeight(Node *node);
	int GetNodes(Node *node,int level,int i=0);
	int getLeafCount( Node *node);

	void print_Tree(Node*p,int level=0);



};
template<class T>
void Tree<T>::DeleteSubTree(Node *node)
{
	if (node)
	{
		DeleteSubTree(node->left);
		DeleteSubTree(node->right);
		delete node;
	}
}
template<class T>

void Tree<T>::print_Tree(Node*p,int level)
{
	if (p)
	{
		print_Tree(p->left,level+1);
		for (int i = 0; i < level; i++) std::cout << "   ";
		std::cout << p->item << std::endl;
		print_Tree(p->right,level+1);
	}
}
template<class T>
int Tree<T>::GetHeight(Node *node)
{
	int r, l, height = 0;
	if (node)
	{
		r = node->right ? GetHeight(node->right) + 1 : 0;
		l = node->left ? GetHeight(node->left) + 1 : 0;
		height += (r > l ? r : l);
	}
	return height;

}
template<class T>

int Tree<T>::getLeafCount( Node *node)
{
	if (node == nullptr)
		return 0;
	if (node->left == nullptr && node->right == nullptr)
		return 1;
	else
		return getLeafCount(node->left) +
		getLeafCount(node->right);
}

template<class T>

void Tree<T>::Add(Node *&node, const T &item)
{
	if (node == nullptr)
	{
		node = new Node(item);
		arr[index]= node->item;
		index++;
	}
	else if (item <= node->item)
		Add(node->left, item);
	else
		Add(node->right, item);
}
template<class T>

void Tree<T>::AddF(Node *&node, const T &item)
{
	if (node == nullptr)
	{
		node = new Node(item);
		arr[index] = node->item;
	index++;
	}
	else if (item >= node->item)
		Add(node->left, item);
	else
		Add(node->right, item);
}
template<class T>

int Tree<T>::GetNodes(Node *node, int level,int i)
{

	if (node == nullptr)
		return 0;
	else if (i == level)
		return 1;
	else {
		cnt += GetNodes(node->left, level,i+1);
		cnt += GetNodes(node->right, level,i+1);
	}
	return (i > 0) ? 0 : cnt;
}
template<class T>

bool Tree<T>:: isIsomorphic(Node* n1, Node *n2)
{
	// Both roots are NULL, trees isomorphic by definition
	if (n1 == nullptr && n2 == nullptr)
		return true;

	// Exactly one of the n1 and n2 is NULL, trees not isomorphic
	if (n1 == nullptr || n2 == nullptr)
		return false;

	if (n1->item != n2->item)
		return false;

	
	return
		(isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
		(isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}
