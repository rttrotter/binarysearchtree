// include other header files (if any)
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "node.h"
#include "btree.h"
 template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
	/*
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
    */


public:


/*********************************************
Insert: 
purpose: public function for super insert method
**********************************************/
void Insert(const T &x)
{
	BinaryTree<T>::Insert(x);
}
/**********************************************

Search:
purpose: to call _search and return it's status

***********************************************/
bool Search(const T &x) const
{
	
	bool s =_Search(this->root, x);
	return s;
}
/**********************************************
Remove:
Purpose: to call Search and make sure that the 
object is in our binary tree before calling remove
to delete it.


***********************************************/
bool Remove(const T &x)
{
	bool found = Search(x);
	if(found) 
	{

		_Remove(this->root, x);
	}

	return found;
	
}


private:
/**********************************************
_search
input Node<T>, T
purpose: checks to see if the data is in the current 
node before deciding to go left or right down the 
tree to the next node. 


***********************************************/

bool _Search(Node<T> *N, const T &d) const
{
	if(N->data == d)
	{
		if(_Leaf(N))
		{
			cout << endl << "found a leaf" << endl;
		return true;
		}
		else return false;
	}
	else
	{
		if(N->left != NULL && N->data < d)
			return  _Search(N->left, d);
		if(N->right !=NULL && N->data > d)
			return _Search(N->right, d);
		return false;
	}
}


/**********************************************

_Remove
inputs: node<T> T
purpose: To remove the specified object from 
the tree if it is a leaf.

***********************************************/


void _Remove(Node<T> *&N, const T &d)
{
	
	
	bool forward = true;
  	if(N->left != NULL && N->left->data == d)//first we check if the right branch exists
	{
			cout << endl << "found " << d << " Left" << endl;
			if(_Leaf(N->left))
			{
				remove(N->left);
				N->left = NULL;//set the pointer to null after deleting the node so we don't segfault
			}
			forward = false;
	}
	if(N->right !=NULL && N->right->data == d)// check to see if the right branch exists 
	{

			cout << endl << "found " << d << " Right" << endl;
			if(_Leaf(N->right))
			{
				remove(N->right);
				N->right = NULL;// set the pointer to null after deleting so we don't segfault
			}
			forward = false;
	}
	if(forward)
	{
		if(N->left != NULL && N->data < d)// if left isn't null, and is less than our current node, travel left
			_Remove(N->left, d);
		if(N->right !=NULL && N->data > d) // if right isn't null and greater than our current node, travel right
			_Remove(N->right, d);
	}
}


/**********************************************
_leaf
inputs: Node T
purpose, checks if Right and left is null and returns true if node is a leaf 


***********************************************/
bool _Leaf(Node<T> *N) const
{
	if(N->left == NULL && N->right == NULL)
	{
		return true;
	}
	else
		return false;
}

void remove(Node<T> *N)
{
	N->data = NULL;
	delete(N);
}


};




#endif // End of BINARYSEARCHTREE_H_