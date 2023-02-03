#pragma once

#include ".../colors/colors.hpp"

#include <iostream>

// BINARY SEARCH TREE ---------------------------------------------------------------------------------------------

template <typename Key, typename Value>
class TreeNode
{
	public:
		Key key;
		Value value;
		TreeNode<Key, Value> *left;
		TreeNode<Key, Value> *right;

  		TreeNode(const Key & key, const Value & value)
      	: key(key)
		, value(value)
		, left(0)
		, right(0)
		{};
};

template <typename Key, typename Value>
class BinarySearchTree
{
	public:
		// default constructor
		BinarySearchTree()
		: root_(0)
		{}

		// insert new node
		void insert(const Key &key, const Value &value)
		{
			root_ = insertHelper(root_, key, value);
		}
	
		// accessor
		Value &operator[](const Key &key)
		{
			TreeNode<Key, Value> *node = findNode(root_, key);
			
			if (node == 0)
				node = insertHelper(root_, key, Value());
			return node->value;
		}

		// print all the keys and values of the tree
		void	printTree(TreeNode<Key, Value> *root)
		{
			if (root != NULL)
			{
				printTree(root->left);
				std::cout << "key = " << root->key << " | value = " << root->value << std::endl;
				printTree(root->right);
			}
		}

		// return a pointer to root node
		TreeNode<Key, Value> *getRoot() const
		{
			return root_;
		}

	private:
		TreeNode<Key, Value> *root_;
		
		// recursive function, used to insert a new node
		TreeNode<Key, Value> *insertHelper(TreeNode<Key, Value> *node, const Key &key, const Value &value)
		{
			if (node == 0)
				return new TreeNode<Key, Value>(key, value);
			if (key < node->key)
				node->left = insertHelper(node->left, key, value);
			else if (node->key < key)
				node->right = insertHelper(node->right, key, value);
			else
				node->value = value;
			return node;
		};

		// a function that searches a specific node and returns it
		TreeNode<Key, Value> *findNode(TreeNode<Key, Value> *node, const Key &key) const
		{
			while (node != 0 && node->key != key)
			{
				if (key < node->key)
					node = node->left;
				else
					node = node->right;
			}
			return node;
		};
};