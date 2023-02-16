#include <stack>
#include <utility>
#include <cstddef>

template <typename T>
class mapIterator
{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;

    mapIterator()
	{};

    mapIterator(typename RBTree<T>::Node* root) {
        if (root) {
            node_stack.push(std::make_pair(root, false));
            increment();
        }
    }

    reference operator*() const { return node_stack.top().first->data; }
    pointer operator->() const { return &node_stack.top().first->data; }

    mapIterator& operator++() { increment(); return *this; }
    mapIterator operator++(int) { mapIterator it = *this; increment(); return it; }

    mapIterator& operator--() { decrement(); return *this; }
    mapIterator operator--(int) { mapIterator it = *this; decrement(); return it; }

    bool operator==(const mapIterator& other) const { return node_stack == other.node_stack; }
    bool operator!=(const mapIterator& other) const { return !(*this == other); }

private:
    std::stack<std::pair<typename RBTree<T>::Node*, bool> > node_stack;

    void increment() {
        if (node_stack.empty()) return;
        typename RBTree<T>::Node* node = node_stack.top().first;
        bool visited = node_stack.top().second;
        node_stack.pop();
        if (!visited) {
            if (node->right) {
                node_stack.push(std::make_pair(node->right, false));
            }
            node_stack.push(std::make_pair(node, true));
            if (node->left) {
                node_stack.push(std::make_pair(node->left, false));
            }
            increment();
        }
    }

    void decrement() {
        if (node_stack.empty()) return;
        typename RBTree<T>::Node* node = node_stack.top().first;
        bool visited = node_stack.top().second;
        node_stack.pop();
        if (visited) {
            if (node->left) {
                node_stack.push(std::make_pair(node->left, true));
            }
            node_stack.push(std::make_pair(node, false));
            if (node->right) {
                node_stack.push(std::make_pair(node->right, true));
            }
            decrement();
        }
    }
};
