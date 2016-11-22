#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class MyLinkedList {
    private:
    Node* head;
    void reverseList(Node* head) {
        if (!head->next) {
            this->head = head;
            return;
        }
        reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
    }
    
    public:
    MyLinkedList() {
        head = NULL;
    }
    ~MyLinkedList() {
        Node* cur = head;
        while (head) {
            head = head->next;
            delete cur;
            cur = head;
        }
    }
    void insert(int val) {
        if (!head) {
            head = new Node;
            head->value = val;
        } else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = new Node;
            cur->next->value = val;
        }
    }
    void display() {
        if (!head) {
            return;
        }
        Node* cur = this->head;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    void reverse() {
        if (!head) {
            return;
        }
        reverseList(this->head);
    }
};

int main() {
    MyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.display();
    list.reverse();
    list.display();
    return 0;
}

