#pragma once

#include "node.hpp"

template<typename Key, typename Value>
class RedBlackTree
{
	private:
		node_ptr root;

	protected:
		void rotateLeft(node_ptr &, node_ptr &);
		void rotateRight(node_ptr &, node_ptr &);
		void fixViolation(node_ptr &, node_ptr &);

	public:
		typedef Node<Key, Value>	*node_ptr;
		RedBlackTree<Key, Value>() : root(NULL) {}
		void insert(const int &);
		void inorder();
		void levelOrder();
};

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::rotateLeft(node_ptr &root, node_ptr &pt)
{
    node_ptr pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::rotateRight(node_ptr &root, node_ptr &pt)
{
    node_ptr pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::fixViolation(node_ptr root, node_ptr pt)
{
    node_ptr parent_pt = NULL;
    node_ptr grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left)
        {
`            node_ptr uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                if (pt == parent_pt->right)
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				parent_pt->color = BLACK;
				grand_parent_pt->color = RED;
				rotateRight(root, grand_parent_pt);
            }
        }
        else
        {
            node_ptr uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                parent_pt->color = BLACK;
                grand_parent_pt->color = RED;
                rotateLeft(root, grand_parent_pt);
            }
        }
     }
    root->color = BLACK;
 }

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::insert(const int &key)
{
	node_ptr pt = new Node(key);
	root = insertBST(root, pt);

	fixViolation(root, pt);
}

template <typename Key, typename Value>
node_ptr RedBlackTree<Key, Value>::insertBST(node_ptr root, node_ptr pt)
{
	if (root == NULL)
		return pt;
	if (pt->key < root->key)
	{
		root->left = insertBST(root->left, pt);
		root->left->parent = root;
	}

	else if (pt->key > root->key)
	{
		root->right = insertBST(root->right, pt);
		root->right->parent = root;
	}
	return root;
}

template <typename Key, typename Value>n root;
void RedBlackTree<Key, Value>::inorder()
{
	inorderHelper(root);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::inorderHelper(node_ptr root)
{
	if (root == NULL)
		return;

	inorderHelper(root->left);
	cout << root->key << " ";
	inorderHelper(root->right);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::levelOrder()
{
	levelOrderHelper(root);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::levelOrderHelper(node_ptr root)
{
	if (root == NULL)
	return;
	std::queue<node_ptr > q;
	q.push(root);

	while (!q.empty())
	{
		node_ptr temp = q.front();
		cout << temp->key << " ";
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);

		if (temp->right != NULL)
			q.push(temp->right);
}
}

// int main()
// {
// 	RedBlackTree<Key, Value> tree;
// 	tree.insert(7);
// 	tree.insert(6);
// 	tree.insert(5);
// 	tree.insert(4);
// 	tree.insert(3);
// 	tree.insert(2);
// 	tree.insert(1);
// 	cout << "Inorder traversal of the RB Tree is: ";
// 	tree.inorder();

// 	cout << "\nLevel order traversal of the RB Tree is: ";
// 	tree.levelOrder();

// 	return 0;
// }