// code to insert a node at a given position in a doubly linked list
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next,*prev;
    node(int new_data){
        data=new_data;
        next=prev=nullptr;
    }
};
node* insertAtFront(node* head,int pos,int new_data){
    node*new_node=new node(new_data);
    if (pos == 1) {
        new_node->next = head;
        if (head != NULL)
            head->prev = new_node;
            head = new_node;
        return head;
    }
    node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }
    if (curr == NULL) {
        delete new_node;
        return head;
    }
    new_node->prev = curr;
    new_node->next = curr->next;
    curr->next = new_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    return head;
}
void printList(node* head) {
    node* curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) {
            cout << " <-> ";
        }
        curr = curr->next;
    }
    cout << endl;
}