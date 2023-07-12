#pragma once
#include<algorithm>
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}

	void remove(T val) override;
	typename Tree<T>::Node* recRemove(T val, typename Tree<T>::Node* children);
	typename Tree<T>::Node* nodeSuccessor(typename Tree<T>::Node*);

	typename Tree<T>::Node* recursiveSearch(typename Tree<T>::Node* current, T val);
	T successor(T val);
	T Recsuccessor(typename Tree<T>::Node* root, T val, T max);
	void deleteDuplicates();
	void recDeleteDuplicate(typename Tree<T>::Node*);


private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)
	{
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	}
	else
	{
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
	}
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

//functions that i added to help other functions

template<class T>
inline void SearchTree<T>::remove(T val)
{
	if (search(val))
		Tree<T>::root = recRemove(val, this->root);
	else
		throw "the value not found : can't be delete\n";
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::recRemove(T val, typename Tree<T>::Node* root)
{
	if (!root)
		return NULL;
	else if (val < root->value)
		root->left = recRemove(val, root->left);
	else if (val > root->value)
		root->right = recRemove(val, root->right);
	else
	{
		if (root->left == nullptr && root->right == nullptr) // zero child
		{
			root = nullptr;
		}
		else if (root->left == nullptr && root->right != nullptr) // one right child 
		{
			typename Tree<T>::Node* temp = root;
			root = root->right;
			temp = nullptr;
			delete temp;

		}
		else if (root->left != nullptr && root->right == nullptr) // one left child
		{
			typename Tree<T>::Node* temp = root;
			root = root->left;
			temp = nullptr;
			delete temp;
		}
		else // two child 
		{
			typename Tree<T>::Node* temp = nodeSuccessor(root->right);
			root->value = temp->value;
			root->right = recRemove(temp->value, root->right);
		}
	}
	return root;
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::nodeSuccessor(typename Tree<T>::Node* current)
{
	while (current->left)
		current = current->left;
	return current;
}



template<class T>
inline typename Tree<T>::Node* SearchTree<T>::recursiveSearch(typename Tree<T>::Node* current, T val)
{
	if (!current || val == current->value)
		return current;
	if (val < current->value)
		return recursiveSearch(current->left, val);
	else
		return recursiveSearch(current->right, val);
}

template<class T>
inline T SearchTree<T>::successor(T val)
{
	T max = NULL;
	typename Tree<T>::Node* temp = recursiveSearch(Tree<T>::root, val);
	if (temp->right)
	{
		temp = nodeSuccessor(temp->right);
		return temp->value;
	}
	else
	{
		return Recsuccessor(Tree<T>::root, val, max);
	}
}

template<class T>
inline T SearchTree<T>::Recsuccessor(typename Tree<T>::Node* root, T val, T max)
{
	if (root->value > val)
	{
		max = root->value;
		while (root->value > val)
		{
			max = root->value;
			root = root->left;
		}
		return Recsuccessor(root, val, max);
	}
	else if (root->value < val)
	{
		while (root->value < val)
		{
			root = root->right;
		}
		return Recsuccessor(root, val, max);
	}
	else
	{
		if (max)
			return max;
		else
			throw"no successor";
	}
}

template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	recDeleteDuplicate(this->root);
}

template<class T>
inline void SearchTree<T>::recDeleteDuplicate(typename Tree<T>::Node* current)
{
	if (!current)
		return;
	else
	{
		recDeleteDuplicate(current->left);
		recDeleteDuplicate(current->right);
		current->left = recRemove(current->value, current->left);
		current->right = recRemove(current->value, current->right);
	}
}




