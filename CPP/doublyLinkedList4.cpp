//code to insert a node at end of a doubly linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *prev, *next;
    Node(int x){
        data=x;
        prev=nullptr;
        next=nullptr;
    }
};
Node *insertAtFront(Node *head,int x){
    Node *newNode=new Node(x);
    newNode->next=head;
    if(head!=nullptr)
        head->prev=newNode;
    return newNode;
}
Node *insertAtPos(Node *head,int pos,int x){
    Node *curr=head;
    for(int i=1;i<pos&&curr!=nullptr;++i){ //traverse the list to find the node before the insertion point
        curr=curr->next;
    }
    Node *newNode=new Node(x);
    newNode->next=curr->next;
    newNode->prev=curr;
    if(curr->next!=nullptr)
        curr->next->prev=newNode;
    curr->next=newNode;
    if(curr==nullptr){ //if position is out of bounds
        delete newNode;
        return head;
    }
    newNode->prev=curr; //set the previous pointer of new node to current node
    newNode->next=curr->next; //set the next pointer of new node to the next pointer of current node
    curr->next=newNode; //update the next pointer of current node to new node
    if(newNode->next!=nullptr) //update the previous pointer of the next node to new node if the new node is not the last node
        newNode->next->prev=newNode;
    return head;
}
Node *insertAtEnd(Node *head,int x){
    if(head==nullptr)
        head=new Node;
    else{
        Node *curr=head;
    }
}
void printList(Node *head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!=nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    head->next->next->next=new Node(4);
    head->next->next->next->prev=head->next->next;
    printList(head);
    int x;
    cin>>x;
    head=insertAtFront(head,x);
    printList(head);
    int pos;
    cin>>pos>>x;
    head=insertAtPos(head,pos,x);
    printList(head);
    return 0;
}