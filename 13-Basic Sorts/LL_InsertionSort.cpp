#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    // 1. Check List Length

    // if (length < 2) {
    //     return;
    // }
    // Checks if the list has fewer than 2 elements.

    // If yes, returns because the list is already sorted.

    // 2. Initialize sortedListHead and unsortedListHead

    // Node* sortedListHead = head;
    // Node* unsortedListHead = head->next;
    // sortedListHead->next = nullptr;
    // sortedListHead is set to the list's head node.

    // unsortedListHead starts at the node right after head.

    // sortedListHead's next is set to nullptr.

    // 3. Main While Loop

    // while (unsortedListHead != nullptr) {
    // This loop iterates through the unsorted part of the list.

    // 4. Initialize current Node

    // Node* current = unsortedListHead;
    // unsortedListHead = unsortedListHead->next;
    // current is set to the first node in the unsorted list.

    // unsortedListHead is moved to the next node.

    // 5. Insert at the Start?

    // if (current->value < sortedListHead->value) {
    // Checks if current should be inserted at the start of the sorted list.

    // 6. Update sortedListHead

    // current->next = sortedListHead;
    // sortedListHead = current;
    // Sets current's next node to sortedListHead.

    // Updates sortedListHead to be current.

    // 7. Else Case: Find Insert Position

    // else {
    //     Node* searchPointer = sortedListHead;
    // searchPointer starts at the first node in the sorted list.

    // Used to find the correct position for current.

    // 8. Inner While Loop: Find Insert Position

    // while (searchPointer->next != nullptr && current->value > searchPointer->next->value) {
    // Finds the node after which current should be inserted.

    // 9. Move searchPointer

    // searchPointer = searchPointer->next;
    // Moves searchPointer to the next node for the next iteration.

    // 10. Insert current Node

    // current->next = searchPointer->next;
    // searchPointer->next = current;
    // Inserts current after searchPointer.

    // 11. End of Main Loop

    // }
    // The main loop ends, and the list should be sorted.

    // 12. Update Head and Tail

    // head = sortedListHead;
    // Node* temp = head;
    // while (temp->next != nullptr) {
    //     temp = temp->next;
    // }
    // tail = temp;
    // Updates the head and tail of the sorted list.

    void insertionSort()
    {
        if (length < 2)
            return;
        Node *sortedListHead = head;
        Node *unsortedListHead = head->next;
        sortedListHead->next = nullptr;
        while (unsortedListHead != nullptr)
        {
            Node *current = unsortedListHead;
            unsortedListHead = unsortedListHead->next;
            if (current->value < sortedListHead->value)
            {
                current->next = sortedListHead;
                sortedListHead = current;
            }
            else
            {
                Node *searchPointer = sortedListHead;
                while (searchPointer->next != nullptr && current->value > searchPointer->next->value)
                {
                    searchPointer = searchPointer->next;
                }
                current->next = searchPointer->next;
                searchPointer->next = current;
            }
        }
        head = sortedListHead;
        while (sortedListHead->next != nullptr)
        {
            sortedListHead = sortedListHead->next;
        }
        tail = sortedListHead;
    }
};
