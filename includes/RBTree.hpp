#pragma once

#include <cstdio>
#include <iostream>

// #include "node.hpp"
#include "../colors/colors.hpp"

// The colour of the NULL node is always black
// Always try recoloring first. If recolouring doesn’t work, then we go for rotation.
// If the uncle is red, we do recolour. If the uncle is black, we do rotations and/or
// recolouring.


// enum Color
// {
// 	RED,
// 	BLACK
// };

// struct Node
// {
//     int key;
//     Node *left, *right, *parent;
//     Color color;

//     Node(int key = 0, Node *left = NULL, Node *right = NULL, Node *parent = NULL, Color color = RED)
//         : key(key), left(left), right(right), parent(parent), color(color) {}
// };

// class RedBlackTree
// {
// private:
//     Node *root;

// protected:
//     void rotateLeft(Node *&, Node *&);
//     void rotateRight(Node *&, Node *&);
//     void fixViolation(Node *&, Node *&);

// public:
//     RedBlackTree() : root(NULL) {}
//     void insert(const int &);
//     void inorder();
//     void levelOrder();
// };

// void RedBlackTree::rotateLeft(Node *&root, Node *&pt)
// {
//     Node *pt_right = pt->right;

//     pt->right = pt_right->left;

//     if (pt->right != NULL)
//         pt->right->parent = pt;

//     pt_right->parent = pt->parent;

//     if (pt->parent == NULL)
//         root = pt_right;

//     else if (pt == pt->parent->left)
//         pt->parent->left = pt_right;

//     else
//         pt->parent->right = pt_right;

//     pt_right->left = pt;
//     pt->parent = pt_right;
// }

// void RedBlackTree::rotateRight(Node *&root, Node *&pt)
// {
//     Node *pt_left = pt->left;

//     pt->left = pt_left->right;

//     if (pt->left != NULL)
//         pt->left->parent = pt;

//     pt_left->parent = pt->parent;

//     if (pt->parent == NULL)
//         root = pt_left;

//     else if (pt == pt->parent->left)
//         pt->parent->left = pt_left;

//     else
//         pt->parent->right = pt_left;

//     pt_left->right = pt;
//     pt->parent = pt_left;
// }

// void RedBlackTree::fixViolation(Node *&root, Node *&pt)
// {
//     Node *parent_pt = NULL;
//     Node *grand_parent_pt = NULL;

//     while ((pt != root) && (pt->color != BLACK) &&
//            (pt->parent->color == RED))
//     {

//         parent_pt = pt->parent;
//         grand_parent_pt = pt->parent->parent;

//         if (parent_pt == grand_parent_pt->left)
//         {

//             Node *uncle_pt = grand_parent_pt->right;

//             if (uncle_pt != NULL && uncle_pt->color == RED)
//             {
//                 grand_parent_pt->color = RED;
//                 parent_pt->color = BLACK;
//                 uncle_pt->color = BLACK;
//                 pt = grand_parent_pt;
//             }

//             else
//             {
//                 if (pt == parent_
// right)
// {
// rotateLeft(root, parent_pt);
// pt = parent_pt;
// parent_pt = pt->parent;
// }
//             parent_pt->color = BLACK;
//             grand_parent_pt->color = RED;
//             rotateRight(root, grand_parent_pt);
//         }

//         else
//         {
//             Node *uncle_pt = grand_parent_pt->left;

//             if ((uncle_pt != NULL) && (uncle_pt->color == RED))
//             {
//                 grand_parent_pt->color = RED;
//                 parent_pt->color = BLACK;
//                 uncle_pt->color = BLACK;
//                 pt = grand_parent_pt;
//             }
//             else
//             {
//                 if (pt == parent_pt->left)
//                 {
//                     rotateRight(root, parent_pt);
//                     pt = parent_pt;
//                     parent_pt = pt->parent;
//                 }

//                 parent_pt->color = BLACK;
//                 grand_parent_pt->color = RED;
//                 rotateLeft(root, grand_parent_pt);
//             }
//         }
//     }
//     root->color = BLACK;
// }
// }

// void RedBlackTree::insert(const int &key)
// {
// Node *pt = new Node(key);
// root = insertBST(root, pt);

// fixViolation(root, pt);
// }

// Node *RedBlackTree::insertBST(Node *root, Node *pt)
// {
// if (root == NULL)
// return pt;
// if (pt->key < root->key)
// {
//     root->left = insertBST(root->left, pt);
//     root->left->parent = root;
// }

// else if (pt->key > root->key)
// {
//     root->right = insertBST(root->right, pt);
//     root->right->parent = root;
// }

// return root;
// void RedBlackTree::inorder()
// {
// inorderHelper(root);
// }

// void RedBlackTree::inorderHelper(Node *root)
// {
// if (root == NULL)
// return;

// inorderHelper(root->left);
// cout << root->key << " ";
// inorderHelper(root->right);
// }

// void RedBlackTree::levelOrder()
// {
// levelOrderHelper(root);
// }

// void RedBlackTree::levelOrderHelper(Node *root)
// {
// if (root == NULL)
// return;
// std::queue<Node *> q;
// q.push(root);

// while (!q.empty())
// {
//     Node *temp = q.front();
//     cout << temp->key << " ";
//     q.pop();

//     if (temp->left != NULL)
//         q.push(temp->left);

//     if (temp->right != NULL)
//         q.push(temp->right);
// }
// }

// int main()
// {
// 	RedBlackTree tree;
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