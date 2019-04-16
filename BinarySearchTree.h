
#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"
#include <fstream>
namespace UTEC {

    struct Node {
        Location data;
        Node* right;
        Node* left;
        Node(Location _data): data{_data}, right{nullptr}, left{nullptr}{}
    };

    class BinarySearchTree {
        Node* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Location data);
        void clear();
        bool is_empty();
        Node* get_root();
        Node* search(int position_id);
        void print();
    };

    void load_locations(BinarySearchTree* linked_list, std::string file_name);
    void print_node(Node* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
