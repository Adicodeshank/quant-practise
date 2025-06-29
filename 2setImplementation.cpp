template<typename T>
class MySet {
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

public:
    bool insert(const T& val) {
        return insert_recursive(root, val);
    }

    bool find(const T& val) {
        return find_recursive(root, val);
    }

private:
    bool insert_recursive(Node*& node, const T& val) {
        if (!node) {
            node = new Node(val);
            return true;
        }
        if (val < node->value)
            return insert_recursive(node->left, val);
        else if (val > node->value)
            return insert_recursive(node->right, val);
        return false;  // already exists
    }

    bool find_recursive(Node* node, const T& val) {
        if (!node) return false;
        if (val == node->value) return true;
        if (val < node->value) return find_recursive(node->left, val);
        return find_recursive(node->right, val);
    }
};
