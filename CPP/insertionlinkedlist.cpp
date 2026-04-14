#include <bits/stdc++.h>
using namespace std;

//Define a node in the linked list
class Node {
    public:
    int data;
    Node* next;

    //constructor to initialize a new node with data
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
//function to insert a new node
Node* insertAtFront(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode; //new head of the list
}
//function to print node 
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    //create the linked list 2->3->4->5
    Node*head = new Node(2);
    head -> next = new Node(3);
    head -> next -> next = new Node(4);
    head -> next -> next -> next = new Node(5);
    
    //insert a new node at the front of the list
    int x=1;
    head = insertAtFront(head,x);
    printList(head);
}