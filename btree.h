#ifndef H_BTREE
#define H_BTREE
#include <cstddef>
#include "node.h"
using namespace std;


/********************************************************
Tyler Trotter
z1802019
cis 340
assignment 7 binary trees

I certify this is all my work with the exception of the 
code provided by NIU staff
*********************************************************/
template <typename T> class BinaryTree{
/*
public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree
*/
protected:
    Node<T> *root;                                      // root of tree
/*
private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
*/
public:
BinaryTree()
{
	BinaryTree<T>::root = new Node<T>();
}

unsigned getSize() const
{
	return _getSize(root);
}

unsigned  getHeight() const
{
    return _getHeight(root);
}

void Inorder(void (*P)(const T&))
{
	_Inorder(root, P);
}
virtual void Insert(const T& data)
{
	_Insert(root, data);
}
private:
unsigned _getSize(Node<T> *N) const
{
	static unsigned int count = 0; //used as our counter, static variable to be referenced as we go recursively deeper
	if(N->left != NULL)
		_getSize(N->left);//go left as far as possible
	if(N->right !=NULL)
		_getSize(N->right);//go right as far as possible
	count++;//keep counting
	return count;//top level call will be the only one that returns the full value of count
}

unsigned _getHeight(Node<T> *N) const             // private version of getHeight()
{
	int leftcount = 0;
	int rightcount = 0;
	if(N->left != NULL)
		leftcount = _getHeight(N->left);//navigate left of tree
	if(N->right !=NULL)
		rightcount = _getHeight(N->right);//navigate right of tree
	
	if(leftcount >= rightcount && leftcount != 0)//logic to count the number of levels in the tree
	{
		return leftcount+1;
	}
	else//only pass the largest number to show the "deepest" layer
	{
		return rightcount+1;
	}
	if(N->right !=NULL && N->left != NULL)//base case
		return 1;
	
}

void _Insert(Node<T> *&N, const T& value)             // private version of Insert()
{
	if(_getHeight(root) == 1 && N->data == NULL)//initial setup for tree
	{
		N->data = value;
	}
	else
	{
		if(N->data > value)//if the new value is less than the existing one, put left
		{
			if(N->left == NULL)
				N->left = new Node<T>(value);
			else
				_Insert(N->left, value);
		}
		else if(N->data < value)//if the data is greater, put right, if equal, no action, already exists in the tree
		{
			if(N->right == NULL)
				N->right = new Node<T>(value);
			else
				_Insert(N->right, value);
			_Insert(N->right, value);
		}
	}
}

void _Inorder(Node<T> *N, void (*P)(const T&)) //go left as far as you can, print out the value, go right, repeat
{
	
	if(N->left != NULL)
		_Inorder(N->left, P);
	P(N->data);
	if(N->right !=NULL)
		_Inorder(N->right, P);
}

};
#endif // End of H_BTREE
