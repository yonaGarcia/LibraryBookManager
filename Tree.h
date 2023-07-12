#pragma once
#include <iostream>
#include<algorithm>
#include"QueueVector.h"
using namespace std;

template <class T>
class Tree
{
protected:

	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL){}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
		
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	
	int height() { return height(root); }
	void reflect() { reflect(root); }
	void breadthScan() { breadthScan(root); }

	virtual void process(T val) { cout << val << " "; }
	
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

private:
	//func of tree
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int height(Node*current);
	void reflect(Node*current);
	void breadthScan(Node*current);
	void RecbreadthScan(Node* current, int i);

};






template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template<class T>
inline int Tree<T>::height(Node* current)
{
	if (!current)
		return -1;
	else if (current->left == nullptr && current->right == nullptr)
		return 0;
	else
		return max(height(current->left), height(current->right))+1;
}

template<class T>
inline void Tree<T>::reflect(Node* current)
{
	if (!current)
		return;
	else if (current->left!=nullptr && current->right!=nullptr)
	{
		Node* temp = current->left;
		current->left = current->right;
		current->right = temp;
		reflect(current->left);
		reflect(current->right);
		
	}
	else if (current->left == nullptr && current->right != nullptr)
	{
		current->left = current->right;
		current->right = nullptr;
		reflect(current->left);
	}
	else if (current->right == nullptr && current->left != nullptr)
	{
	current->right= current->left;
	current->left = nullptr;
	reflect(current->right);
	}
}

QueueVector Q(100);

template<class T>
inline void Tree<T>::breadthScan(Node* current)
{
	int size = height(current)+1 ;
	for (int i = 1; i <= size; i++)
		RecbreadthScan(current, i);
	while (!Q.isEmpty())
		cout << Q.dequeue() << ' ';
}

template<class T>
inline void Tree<T>::RecbreadthScan(Node* current, int i)
{
	if (!current)
		return;
	else if (i == 1)
		Q.enqueue(current->value); 
	else if (i > 1)
	{
		RecbreadthScan(current->left, i - 1);
		RecbreadthScan(current->right, i - 1);
	}
}
