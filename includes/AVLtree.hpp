#pragma once

#include <cmath>
#include <iostream>

// AVL tree is a self-balancing Binary Search Tree (BST) where the difference between
// heights of left and right subtrees for any node cannot be more than one.
template<typename Key, typename Value>
class AVLTree
{
	private:
		struct Node
		{
			Node*	left_; // stores a pointer to the child on the left
			Mode*	right_; // stores a pointer to the child on the right
			int		height_; // The height of a node in a tree is defined as the length of the longest path from that node to a leaf node. The height of an empty tree is zero.
			Key		key_; // 1st template parameter
			Value	value_; // 2nd template parameter

			// default constructor
			Node(const Key & key_, const Value & value_)
			: left_(nullptr), right_(nullptr), height_(1), key_(key_), value_(value_)
			{}
		};

		Node *root_; // stores a pointer to the top-most node, the one with no parents

		// if node is nullptr, returns 0, otherwise returns node->height_
		int getHeight(Node *node)
		{
			return node ? node->height_ : 0;
		}

		// returns the difference between the number of nodes on the left 
		// of the subtree and the number of nodes on the right of the subtree.
		
		// In a binary tree the balance factor of a node X is defined to be the
		// height difference :
    	// BF ( X ) := Height ( RightSubtree ( X ) ) − Height ( LeftSubtree ( X ) ) {\displaystyle {\text{BF}}(X):={\text{Height}}({\text{RightSubtree}}(X))-{\text{Height}}({\text{LeftSubtree}}(X))} {\displaystyle {\text{BF}}(X):={\text{Height}}({\text{RightSubtree}}(X))-{\text{Height}}({\text{LeftSubtree}}(X))}
		int balanceFactor(Node *node)
		{
			return getHeight(node->right_) - getHeight(node->left_);
		}

		// RIGHT ROTATION - RR rotation
		/*         a
		*          /
		*         b    --->     b
		*        /             / \
		*  	    c             c   a  
		*/

		Node* right_Rotate(Node *y)
		{
			Node *x = y->left_;
			Node *T2 = x->right_;

			x->right_ = y;
			y->left_ = T2;

			y->height_ = std::max(getHeight(y->left_), getHeight(y->right_)) + 1;
			x->height_ = std::max(getHeight(x->left_), getHeight(x->right_)) + 1;

			return x;
		}

		// LEFT ROTATION - LL rotation

		/*     a 
		*       \ 
		*        b    --->     b
		*         \           / \
		*          c         a   c
		*/
	    // A left rotation is a balancing technique that is applied on an unbalanced 
		// AVL Tree on a node having the balance_factor > 1.
		Node* left_Rotate(Node *x)
		{
			Node *y = x->right_;
			Node *T2 = y->left_;

			y->left_ = x;
			x->right_ = T2;

			x->height_ = std::max(getHeight(x->left_), getHeight(x->right_)) + 1;
			y->height_ = std::max(getHeight(y->left_), getHeight(y->right_)) + 1;

			return y;
		}

		Node* insert(Node *node, const Key &key_, const Value &value_)
		{
			if (!node)
			{
				return new Node(key_, value_);
			}

			if (key_ < node->key_)
			{
				node->left_ = insert(node->left_, key_, value_);
			}
			else if (node->key_ < key_)
			{
				node->right_ = insert(node->right_, key_, value_);
			}
			else
			{
				node->value_ = value_;
			}

			node->height_ = std::max(getHeight(node->left_), getHeight(node->right_)) + 1;

			int balance = balanceFactor(node);

			if (balance > 1 && key_ < node->right_->key_)
			{
				return left_Rotate(node);
			}

			if (balance < -1 && key_ < node->left_->key_)
			{
				return right_Rotate(node);
			}

			if (balance > 1 && key_ > node->right_->key_)
			{
				node->right_ = right_Rotate(node->right_);
				return left_Rotate(node);
			}

			if (balance < -1 && key_ < node->left_->key_)
			{
				node->left_ = left_Rotate(node->left_);
				return right_Rotate(node);
			}

			return node;
		}

	public:
		AVLTree()
		: root_(nullptr)
		{}

		void insert(const Key &key_, const Value &value_)
		{
			root_ = insert(root_, key_, value_);
		}

		// add get and remove methods
};
