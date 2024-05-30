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
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
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
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
        // void prepend(int value) {
        //     Node* newNode = new Node(value);
        //     if (head == nullptr) {
        //         head = newNode;
        //     } else {
        //         newNode -> next = head;
        //         head = newNode;
        //     }
        //     length++;
        // }

        void partitionList(int x){
            if(head == nullptr) return;
            if(length == 1) return;
            // if(x>)
            Node* firHead = nullptr;
            Node* secHead = nullptr;
            Node* firTemp = nullptr;
            Node* secTemp = nullptr;
            Node* temp = head;
            for(int i = 0; i < length; i++) {
                if(temp->value < x) {
                    if(firHead==nullptr)
                    {
                        firHead = temp;
                        firTemp = firHead;
                    }
                    else{
                        firTemp -> next = temp;
                        firTemp = temp;
                    }
                }else{
                    if(secHead==nullptr){
                        secHead = temp;
                        secTemp = secHead;
                    }
                    else{
                        secTemp -> next = temp;
                        secTemp = temp;
                    }
                }
                temp = temp->next;
            }
            if(secTemp == nullptr){
                head = firHead;
            }else if(firHead == nullptr){
                head = secHead;
            }else{
                secTemp -> next = nullptr;
                head = firHead;
                firTemp -> next = secHead;
            }
        }
        /**
         * 
            1 -> 2 -> 3 -> 2 -> 4 -> 5 -> 3 -> nullptr
            result:
            1 -> 2 -> 3 -> 4 -> 5 -> nullpt
        */
        void removeDuplicates(){
            if(head == nullptr) return;
            Node* cur = head;
            Node* temp = cur->next;
            Node* pre = cur;
            for(int i = 0; i < length-1; i++){
                for(int j = i+1; j < length; j++){
                    if(temp->value == cur->value){
                        pre -> next = temp -> next;
                        temp = pre -> next;
                        length--;
                    }
                    pre = pre->next;
                    temp = temp->next;
                }
                cur = cur->next;
                temp = cur->next;
                pre = cur;
            }
        }
        /**
         * 
        */
        int binaryToDecimal(){
            int num = 0;
            Node* temp = head;
            // if(length == 1){
            //     return 1;
            // }
            for(int i = 0; i <length; i++){
                num = num * 2+ temp->value;
                temp=temp->next ;
            }
            return num;
        }
};

