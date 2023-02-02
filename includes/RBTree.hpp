#pragma once

#include <iostream>
#include "node.hpp"

#include "../colors/colors.hpp"

// The colour of the NULL node is always black
// Always try recoloring first. If recolouring doesn’t work, then we go for rotation.
// If the uncle is red, we do recolour. If the uncle is black, we do rotations and/or
// recolouring.


template<typename Key, typename Value>
	class RBTree
	{
		typedef Node<Key, Value> Node;

		private:
			Node *root;

		public:
			RBTree()
			: root(0)
			{};

			// insert a new node with a given key and value
			// the param node should always be the root node
			// of the binary tree.
			Node *insert(Node *node, Key key, Value value)
			{
				if (node == NULL)
					return new Node(key, value);
				if (key < node->key_)
				{
					node->left_ = insert(node->left_, key, value);
				}
				else if (key > node->key_)
				{
					node->right_ = insert(node->right_, key, value);
				}
				return new Node(key, value);
			};

			void print_tree(Node* root)
			{
				std::cout << RED << "root = " << root << RESET << std::endl;
				if (root != NULL)
				{
					print_tree(root->left_);
					std::cout << root->key_ << " ";
					print_tree(root->right_);
				}
			}
			// void rotateLeft(Node *&, Node *&);
			// void rotateRight(Node *&, Node *&);

	};