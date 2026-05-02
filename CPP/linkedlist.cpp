#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;
    node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};
node* insertdata(node* head, int data) {
    node* new_node = new node(data);
    if (head != nullptr) {
        new_node->next = head;
        head->prev = new_node;
    }
    return new_node; // new node becomes new head
}
void printlist(node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    node* head = new node(2);
    head->next = new node(3);
    head->next->prev = head;
    head->next->next = new node(4);
    head->next->next->prev = head->next;
    int data=1;
    head = insertdata(head, data);
    printlist(head);
    return 0;
}