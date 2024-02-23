#include <iostream>

struct node {
    int data;
    node *left;
    node *right;

};

struct bst {

public:
    node *root = nullptr;

    node *find(int value) {
        return find_impl(root, value);

    }

    void insert(int value) {
        if (!root) {
            root = new node(value, NULL, NULL);
        } else
            insert_impl(root, value);
    }

    void inorder() {
        inorder_impl(root);
    }

    node *successor(node *start) {
        auto current = start->right;
        while (current && start->right)
            current = current->left;
        return current;
    }

    void deleteValue(int value) {
        root = delete_impl(root, value);
    }

private:
    node *find_impl(node *current, int value) {
        if (!current) {
            std::cout << std::endl;
            return NULL;
        }

        if (current->data == value) {
            std::cout << value << "을(를) 찾았습니다." << std::endl;
            return current;
        }

        if (current->data < value) {
            std::cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);

        }
        std::cout << current->data << "에서 오른쪽으로 이동: ";
        return find_impl(current->right, value);

    }

    node *insert_impl(node *current, int value) {
        if (current->data < value) {
            if (!current->left)
                current->left = new node{value, NULL, NULL};
            else
                insert_impl(current->left, value);
        } else {
            if (!current->right)
                current->right = new node{value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }

    void inorder_impl(node *start) {
        if (!start)
            return;
        inorder_impl(start->left);
        std::cout << start->data << " ";
        inorder_impl(start->right);
    }

    node *delete_impl(node *start, int value) {
        if (!start)
            return;

        if (start->data < value)
            start->left = delete_impl(start->left, value);
        else if (start->data > value) {
            start->right = delete_impl(start->right, value);
        } else {
            if (!start->left) {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            if (!start->right) {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            auto succNode = successor(start);
            start->data = succNode->data;

            // 이게 어렵네, 와 이걸 이렇게 한다고 대박
            start->right = delete_impl(start->right, succNode->data);
        }
        return start;
    }
};
