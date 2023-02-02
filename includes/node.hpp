#pragma once

enum Color
{
	RED,
	BLACK
};

// defines a single node in the red-black tree
template<typename Key, typename Value>
	struct Node
	{
		Key		key_; // 1st template parameter
		Value	value_; // 2nd template parameter
		bool	color_;
		Node	*left_; // stores a pointer to the child on the left
		Node	*right_; // stores a pointer to the child on the right
		Node	*parent_; // stores a pointer to the parent of the node

		// default constructor
		Node(Key key, Value value)
		: key_(key)
		, value_(value)
		, color_(RED)
		, left_(NULL)
		, right_(NULL)
		, parent_(NULL)
		{}
	};