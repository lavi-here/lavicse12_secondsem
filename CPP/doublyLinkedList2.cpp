// code to delete the head node of a singly linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function moved outside or made static for easier access
Node* deletehead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;      // Save the current head
    head = head->next;      // Move head to the next node
    delete temp;            // Free the memory of the old head
    return head;            // Return the new starting point
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next; // Move to the next node
    }
    cout << " -> nullptr" << endl;
}

int main() {
    // Creating the list: 8 -> 2 -> 1
    Node* head = new Node(8);
    head->next = new Node(2);
    head->next->next = new Node(1);

    cout << "Original list: ";
    printList(head);

    head = deletehead(head);

    cout << "After deleting head: ";
    printList(head);

    return 0;
}