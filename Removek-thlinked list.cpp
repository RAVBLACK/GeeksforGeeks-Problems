// C++ program to delete every k-th Node of
// a singly linked list.
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

// Function to remove every kth node in the linked list
Node* deleteK(Node* head, int k) {
  
    // If list is empty or k is 0, return the head
    if (head == nullptr || k <= 0) 
        return head;

    Node* curr = head;
    Node* prev = nullptr;
    
    // Initialize counter to track node positions
    int count = 0;

    // Traverse the linked list
    while (curr != nullptr) {
        count++;

        // If count is a multiple of k, remove current node
        if (count % k == 0) {
          
            // skip the current node
            if (prev != nullptr) {
                prev->next = curr->next;
            } 
            else {
              
                head = curr->next;
            }
        } 
        else {
          
            // Update previous node pointer only if
            // we do not remove the node
            prev = curr;
        }
        curr = curr->next;
    }
  
    return head;
}

void printList(Node* head) {
  
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    int k = 2;
    head = deleteK(head, k);
    printList(head);

    return 0;
}
