
#include "BinarySearchTree.h"
bool UTEC::BinarySearchTree::is_empty() {
    return root == nullptr;
}
UTEC::BinarySearchTree::BinarySearchTree() : root{nullptr}{}
UTEC::Node* UTEC::BinarySearchTree::get_root() {
    return root;
}
void UTEC::BinarySearchTree::print() {
    Node* temp = root;
    while(temp != nullptr){
    }
}
void UTEC::BinarySearchTree::insert(Location data) {
    Node* nuevo = new Node(data);
    Node* temp = root;
    if(root != nullptr){
        while ( 1 == 1 ){
            if( nuevo->data.get_pos() <  temp->data.get_pos()){
                //menor
                if(temp->left == nullptr){
                    temp->left =  nuevo;
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                //Mayor
                if(temp->right == nullptr){
                    temp->right = nuevo;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
    else{
    root = nuevo;}
}
UTEC::Node * UTEC::BinarySearchTree::search(int position_id) {
    Node *temp = root;
    if (position_id == temp->data.get_pos()) {
        return temp;
    } else {
        while (1 == 1) {
            if (position_id < temp->data.get_pos()) {
                if (temp->left->data.get_pos() == position_id) {
                    return temp->left;
                } else {
                    temp = temp->left;
                }
            } else {
               if( temp->right->data.get_pos() == position_id ){
                   return temp->right;
               }
               else{
                   temp  = temp->right;
               }
            }
            if( temp ->right == nullptr && temp->left == nullptr)
                return nullptr;
        }
    }
}
void UTEC::load_locations(UTEC::BinarySearchTree *linked_list, std::string file_name) {
    std::fstream file(file_name, std::ios::in);
    std::string local;
    getline(file,local);
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;
    for(int i  = 0 ; i < 36336; i++ ) {
        getline(file, local, ',');
        position_id = atoi(local.c_str());
        getline(file, local, ',');
        state_code = local;
        getline(file, local, ',');
        county = local;
        getline(file, local, ',');
        latitude = atoi(local.c_str());
        getline(file, local, ',');
        longitude = atoi(local.c_str());
        getline(file, local, ',');
        line = local;
        getline(file, local, ',');
        construction = local;
        Location a(position_id, state_code, county, latitude, longitude, line, construction);
        linked_list->insert(a);
    }
}
