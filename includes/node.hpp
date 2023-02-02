#pragma once

// defines a single node in the AVL tree
template <typename T>
	struct node
	{
		T data_;
		int height_;
		node* left_;
		node* right_;
	
		node(T data) : data_(data), height_(1), left_(nullptr), right_(nullptr) {}
	};