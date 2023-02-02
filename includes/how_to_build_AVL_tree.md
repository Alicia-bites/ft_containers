    Define a node structure: This structure will represent a single node in the AVL tree and will contain the data, pointers to its left and right children, and a balance factor.

    Implement the insert function: The insert function is used to add new elements to the tree. The function first inserts the new node in the appropriate position in the tree and then updates the balance factors of all affected nodes.

    Implement the balance function: The balance function is used to balance the tree after an insertion. It checks the balance factors of the nodes and, if necessary, rotates the tree to restore balance.

    Implement the delete function: The delete function is used to remove elements from the tree. The function first finds the node to be deleted and then deletes it, updating the balance factors of all affected nodes as necessary.

    Implement the search function: The search function is used to find elements in the tree. The function starts at the root of the tree and compares the target data with the data stored in the current node. If the target data is smaller, it moves to the left child, otherwise it moves to the right child. The process repeats until the target data is found or there are no more nodes to explore.

    Implement the traverse function: The traverse function is used to traverse the tree in a specific order, such as in-order, pre-order, or post-order. The function visits all nodes of the tree by visiting the left subtree first, then the current node, and finally the right subtree.

These are the basic steps to build an AVL tree in C++98. You may also want to add additional functions, such as finding the minimum or maximum element in the tree, finding the height of the tree, and so on.