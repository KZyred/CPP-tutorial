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
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
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

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
            length = 0;
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
            length++;
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Check if the linked list has a loop                |
        //   | - Return type: bool                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - If they meet, a loop exists                        |
        //   | - Return true if loop found, false otherwise         |
        //   | - 'fast' checks for null and its 'next' for null     |
        //   +======================================================+
        bool hasLoop(){
            Node* fast = head;
            Node* slow = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow){
                    return true;
                }
            }
            return false;
        } 

};

int main(){
    LinkedList* mylist = new LinkedList(3);
    mylist->append(9);
    mylist->append(10);

    cout << "My List" << endl;
    mylist->printList();

    cout << "arg" << endl;
    cout << mylist->hasLoop()->value << endl;

}


