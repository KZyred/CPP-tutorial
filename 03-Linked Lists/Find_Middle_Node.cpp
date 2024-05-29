#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        /**
         * một cách chậm, phải duyệt qua list 2 lần
        */
        Node* findMiddleNode(){
            // tim length -> while
            int length = 0;
            Node* temp = head;
            while (temp)
            {
                temp = temp->next;
                length++;
            }
            int arverge = length/2;
            temp = head;
            for(int i = 0; i < arverge; i++){
                temp = temp->next;
            }
            return temp;
        }
        /**
         * dùng fast and slow pointer (hay còn gọi là rùa và thỏ)
         * Vận tốc của fast luôn gấp đôi slow trên cùng một quãng đường đi
         * https://medium.com/@arifimran5/fast-and-slow-pointer-pattern-in-linked-list-43647869ac99
        */
        Node* findMiddleNode2(){
            Node* fast = head;
            Node* slow = head;
            while(fast != nullptr && fast->next != nullptr) { 
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
};

int main(){
    LinkedList* mylist = new LinkedList(3);
    mylist->append(9);
    mylist->append(10);

    cout << "My List" << endl;
    mylist->printList();

    cout << "arg" << endl;
    cout << mylist->findMiddleNode2()->value << endl;

}


