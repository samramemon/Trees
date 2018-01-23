/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *
 */

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>
using namespace std;

/*
 *  Node datastructure for single tree node
 */ 
template <class T>
struct Node {
	T mData;
	Node *mpLeft;
	Node *mpRight;

};


/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST {

    private:
	Node<T> *root;
	int treeSize;
	int count;
    public:
		BST <T> ()
		{
			root = nullptr;

		}
		Node <T> *&getRoot()
		{
			return root;
	}
		int getCount()
		{
			return count;
		}
		void setCount(int &newCount)
		{
			count = newCount;
		}

    void add(T val, Node<T> *&root)
	{
			if (root == NULL)
			{
				Node <T> *pMem= new Node<T>;
				pMem->mData = val;
				pMem->mpLeft = nullptr;
				pMem->mpRight = nullptr;
				root = pMem;
			}
				
			else if (val < root->mData)
					add(val, root->mpLeft);
			else if (val>root->mData)
					add(val, root->mpRight);
			
		
    }

    void print() {
			this->printPreOrder(root);
    }

    void printPreOrder(Node<T> *&root) {
	  if (root == nullptr)
		  return;
	  
		  cout << root->mData << endl; // processed
		  printPreOrder(root->mpLeft); // go left
		  printPreOrder(root->mpRight); // go right

    }

    int nodesCount(Node <T> *pTree) 
	{
		if (root == nullptr)
			return 0;

		int leftTree = height(root->mpLeft);
		int rightTree = height(root->mpRight);
		return leftTree + rightTree + 1;
    }

    int height(Node <T> *&root) {
		
	  if (root == nullptr)
		  return -1;
	  
		  int leftTree= height(root->mpLeft);
		  int rightTree = height(root->mpRight);
		  if (leftTree > rightTree) 
			  return leftTree + 1;
		  else 
			  return rightTree + 1;
		  
    }
};

#endif
