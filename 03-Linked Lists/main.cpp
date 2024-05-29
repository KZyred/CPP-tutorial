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
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
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

        void deleteLast() {
            Node* temp = head;
            if(head == nullptr){
                return;
            }
            if(length == 1){
                head = nullptr;
                tail = nullptr;
                length --;
                delete temp;
            }else{
                while (temp)
                {
                    if(temp->next == tail){
                        temp->next = nullptr;
                        delete tail;
                        tail = temp;
                        length--;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
        void prepend(int value) {
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        void deleteFirst() {
            Node* pre = head;
            if(head == nullptr){
                return;
            }else if(length == 1){
                head = nullptr;
                tail = nullptr;
                length = 0;
            }else{
                head = pre->next;
                delete pre;
                length--;
            }
        }
        Node* get(int index) {
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index, int value) {
            if(index < 0 || index >= length){
                return false;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            temp->value = value;
            return true;
        }

        bool insert(int index, int value) {
            Node* newNode = new Node(value);
            if(index < 0 || index > length){
                return false;
            }
            if(index == length){
                append(value);
            }else if(index == 0){
                prepend(value);
            }else {
                Node* temp = get(index -1);
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
            }
            return true;
        }
        void deleteNode(int index){
            Node* temp = head;
            if(index < 0 || index >= length){
                return;
            }
            if(index == 0){
                deleteFirst();
            }else if(index == length - 1 ){
                deleteLast();
            }else{
                Node* pre = get(index-1);
                temp = pre->next;
                pre->next = temp->next;
                delete temp;
                length--;
            }
        }

        void reverse(){
            Node* temp = head;
            Node* before = nullptr;
            Node* pre = temp->next;
            head = tail;
            tail = temp;
            for(int i=0; i < length; i++){
                temp->next = before;
                before = temp;
                temp = pre;
                pre = temp->next;
            }
        }
};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->reverse();


    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << endl << "Linked List:" << endl;
    myLinkedList->printList();  


    /*  
    	EXPECTED OUTPUT:
        ----------------
        Head: 1
        Tail: 2
        Length: 2

        Linked List:
        1
        2

    */
        
}
