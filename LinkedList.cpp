
#include "LinkedList.h"

UTEC::LinkedList::LinkedList(): head{nullptr}, tail{nullptr}{}

UTEC::LinkedList::~LinkedList() {

}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
void UTEC::LinkedList::print() {
    Node* temp = head;
    temp->data.imprimir_Location();
}
UTEC::Node * UTEC::LinkedList::search(int position_id) {
    if(is_empty())
        return nullptr;
    else{
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data.get_pos() == position_id ){
                return temp;
            }
            else{
                temp = temp->next;
            }
        }
    }
}
void UTEC::LinkedList::insert(int position, Location data) {
    Node* nuevo = new Node(data);
    Node* temp = head;
    if(position < size() ) {
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        nuevo->next = temp->next;
        temp->next = nuevo;
    }
}
void UTEC::load_locations(UTEC::LinkedList *linked_list, std::string file_name) {
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
        linked_list->add_head(a);
    }
}
