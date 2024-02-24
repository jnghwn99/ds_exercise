#include <iostream>
#include <queue>

struct node {
    std::string position;
    node *first;
    node *second;

};

struct org_tree {
    node *root;

    static org_tree create_org_structure(const std::string &pos) {
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;

    }

    static node *find(node *root, const std::string &value) {
        if (root == NULL)
            return NULL;

        if (root->position == value)
            return root;

        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);

    }

    bool addSubordinate(const std::string &manager, const std::string &subordinate) {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode) {
            std::cout << manager << "을(를) 찾을 수 없습니댜: " << std::endl;
            return false;

        }

        if (managerNode->first && managerNode->second) {
            std::cout << manager << "아래에 " << subordinate << "을(를) 추가할 수 없습니다. " << std::endl;
            return true;

        }

        if (!managerNode->first)
            managerNode->first = new node{subordinate, NULL, NULL};
        else
            managerNode->second = new node{subordinate, NULL, NULL};

        std::cout << manager << " 아래에 " << subordinate << " 을(를) 추가했습니다." << std::endl;

        return true;

    }

    static void preOrder(node *start) {
        if (!start)
            return;
        std::cout << start->position << ", ";
        preOrder(start->first);
        preOrder(start->second);

    }

    static void inOrder(node *start) {
        if (!start)
            return;
        preOrder(start->first);
        std::cout << start->position << ", ";
        preOrder(start->second);

    }

    static void postOrder(node *start) {
        if (!start)
            return;

        postOrder(start->first);
        postOrder(start->second);
        std::cout << start->position << ", ";

    }

};
