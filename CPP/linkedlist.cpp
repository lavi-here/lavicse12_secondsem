#include <bits/stdc++.h>
using namespace std;

//singly linked list node structure 
class Node {
    public:
    int data;
    Node* next;

    // constructor to initialize a new node with data
    // constructor matlab to automatically initialize new object
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};
int main(){
    //create the first node head and calling of constructor
    //new allocates memory to object
    Node* head = new Node(10);

    //link the second node
    head -> next = new Node(20);

    //link the third node 
    head -> next -> next = new Node(30);

    //link the fourth node
    head -> next -> next -> next = new Node(40);

    //printing linked list
    Node* temp=head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}