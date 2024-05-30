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
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
    
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+



























/*Consider the following singly linked list:
1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    cur temp

For the given list, 
the function ll.reverseBetween(1, 3) should modify the list to be:
1 -> 4 -> 3 -> 2 -> 5 -> nullptr

Giả thiết ban đầu, m n nằm trong bound
không có tail

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+

        prev -> m
        cur -> m+1->n

        m+1->n

*/
        void reverseBetween2(int m, int n){
            if(head == nullptr) return;
            if(m==n) return; 
            if(m==0) return;
            if(n==length-1) return;
            Node *temp = head;
            // if(m==1) 
            //     temp = temp->next; 
            for(int i = 1; i<m; i++){
                temp = temp->next;
            }
            Node *prev = temp;
            Node *current = temp;
            for(int i = m; i<=n; i++){
                current = current->next;
            }
            Node *before = prev; 
            temp = temp->next; 
            Node *after = temp->next;  
            Node *end = current->next; 
            
            for(int i = m; i<=n; i++){
                temp -> next = before;
                before = temp;
                temp = after;
                after = after->next; 
            }
            prev->next->next = end;
            prev->next = current;
        }

        void reverseBetween1(int m, int n) {
            /**
             * Nếu danh sách trống thì không có gì để đảo ngược.
            */
            if (head == nullptr) return;
            /**
             * Nút giả (dummy node) là một thủ thuật được sử dụng để đơn giản hóa các điều kiện biên, 
             * đặc biệt khi điểm bắt đầu đảo ngược là nút đầu tiên.
            */
            Node* dummy = new Node(0); //khởi tạo
            dummy->next = head;         // gán đầu cũ
            /**
             * prev: nút ngay trước nút được đảo ngược
             * 
            */
            Node* prev = dummy;         //prev đầu đã khởi tạo (0)
            /**
             * i = 0: prev = head
             * i = 1: ...
             * ...
             * i = m-1: prev (của m)
             * 
             * => Chẳng hạn, nếu sự đảo ngược bắt đầu ở chỉ số 1, 
             * thì như vậy: prev sẽ trỏ đến nút 1 (tại chỉ số 0).
            */
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
            /**
             * cur trỏ đến nút số 2 (m+1)
            */
            Node* current = prev->next; 
            /**
             * m    m+1 m+2
             * prev cur temp
             * node 1,2,3
            */
            /**
             *  1 2 3 4 5
             * Kết quả sau lần lặp 1: 1 → 3 → 2 → 4 → 5.
             * Kết quả sau lần lặp 2: 1 → 4 → 3 → 2 → 5.
            */
            for (int i = 0; i < n - m; i++) {
                Node* temp = current->next;   // node 3
                current->next = temp->next;     // node 2 trỏ sang node 4
                temp->next = prev->next;    //node 3 trỏ sang node 2
                prev->next = temp;      // node 1 trỏ sang node 3
            }
    
            head = dummy->next;
            delete dummy;

        }


        void reverseBetween(int m, int n) {
            // 1. Initial Check:
            // If the list is empty, there's nothing to reverse.
            // So, exit the function without doing anything.
            if (head == nullptr) return;
        
            // 2. Dummy Node Creation:
            // We initiate a new 'dummy' node with value 0.
            // This is a trick to simplify the edge cases.
            Node* dummy = new Node(0);
        
            // Kết nối danh sách thực tế của chúng tôi ngay sau nút giả.
            // Vì vậy, nút giả tạm thời đứng trước nút đầu.
            dummy->next = head;
        
            // 3. Positioning 'prev':
            // Start with 'prev' pointing to the dummy node.
            Node* prev = dummy;
        
            // Di chuyển 'prev' lên nút ngay trước khi bắt đầu
            // điểm của phần chúng tôi muốn đảo ngược.
            // prev = m
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
        
            // 4. Thiết lập 'hiện tại':
            // 'current' được đặt ngay sau 'prev'.
            // Nó đánh dấu sự bắt đầu của phần cần đảo ngược.
            Node* current = prev->next;
        
            // 5. Logic đảo ngược chính:
            // Bây giờ chúng ta bước vào vòng lặp đảo ngược cốt lõi của mình.
            for (int i = 0; i < n - m; i++) {
                // 'temp' trỏ đến nút ở dòng tiếp theo
                // cho quá trình đảo ngược của chúng tôi.
                Node* temp = current->next;
        
                // Tách 'temp' khỏi chuỗi hiện tại bằng cách
                // làm cho 'hiện tại' bỏ qua 'temp'.
                current->next = temp->next;
        
                // Để di chuyển 'temp' đến đầu phần đảo ngược của chúng ta,
                // trước tiên chúng ta để 'temp' trỏ đến bất kỳ nút nào 'prev' đang trỏ tới.
                temp->next = prev->next;
        
                // Cuối cùng, chúng ta điều chỉnh 'prev' để trỏ đến 'temp', qua đó
                // di chuyển 'temp' lên phía trước phần bị đảo ngược.
                prev->next = temp;
            }
        
            // 6. Cập nhật đầu:
            // Nếu phần đảo ngược của chúng ta bao gồm phần đầu ban đầu của danh sách,
            // phần đầu danh sách của chúng ta sẽ thay đổi.
            // Vì vậy, chúng ta cần cập nhật phần đầu danh sách của mình.
            head = dummy->next;
        
            // 7. Dọn dẹp:
            // Nút giả đã phục vụ mục đích của nó.
            // Chúng ta giải phóng bộ nhớ của nó để tránh rò rỉ bộ nhớ.
            delete dummy;
        }
};


