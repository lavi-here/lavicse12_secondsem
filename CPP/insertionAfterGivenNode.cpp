#include <bits/stdc++.h>
using namespace std;
//Define a node in the linked list
struct Node {
    int data;
    Node* next;
    //constructor to initialize a new node with data
    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

//function to print node 
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//function to insert a new node after a given node
Node* insertAfter(Node* head , int key , int newData){
    Node* curr=head;

    //iterate over linked list to find the key
    while(curr != nullptr){
        if(curr->data == key)
        break;
        curr = curr -> next
    }
    //if curr becomes null means, given key is not found in the linked list
    if(curr == nullptr){
        cout<<"Node not found !!"<<endl;
        return head;
    }

}


int main(){
    //create a hard coded linked list
    // 2 3 4 5
    Node* head = new Node(2);
    head -> next= new Node(3);
    head -> next -> next = new Node(5);
    head -> next -> next -> next = new Node(6);
    
    cout<<"Original linked list ";
    printList(head);

    //key onsert node after key
    int key =3,newData=4;

    //insert a new node with data 4 after the node having data 3
    head = insertAfter(head,key,newData);
    cout<<
}