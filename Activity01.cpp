#include <iostream>
#include <string>
#include <algorithm>

struct circular_ll_node {
    std::string *song;
    circular_ll_node *next;
    circular_ll_node *prev;

    ~circular_ll_node() {
        delete song;
    }

};

class circular_ll {
public:
    using node = circular_ll_node;
    using node_ptr = node *;

    circular_ll() {
        head = new node{nullptr, nullptr, nullptr};
        head->next = head;
        head->prev = head;
    }

    void insert_last(const std::string &song) {
        auto newNode = new node{nullptr, nullptr, nullptr};
        if (head->next != nullptr && head->prev != nullptr)
            newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
    }

    void erase_last() {
        auto cur = head->prev;
        if (head) {
            head->prev = cur->prev;
            cur->prev->next = head;
            delete cur;
        }
    }

    struct circular_ll_it {
    public:
        circular_ll_it(node_ptr p) : ptr(p) {}

        std::string &operator*() {
            return *(ptr->song);
        }

        node_ptr get() {
            return ptr;
        }

        circular_ll_it &operator++() {
            ptr = ptr->next;
            return *this;

        }

        circular_ll_it operator++(int) {
            circular_ll_it it = *this;
            ++(*this);
            return it;
        }

        circular_ll_it &operator--() {
            ptr = ptr->prev;
            return *this;
        }

        circular_ll_it operator--(int) {
            circular_ll_it it = *this;
            --(*this);
            return it;
        }
    private:
        node_ptr ptr;
    };

private:
    node_ptr head;

};

struct playlist {
    circular_ll list;

    void insert(const std::string &song) {
        list.insert_last(song);
    }

    void erase() {
        list.erase_last();
    }
};

int main() {
    std::cout << "hello";
    playlist p1;
    p1.insert("a");

}
