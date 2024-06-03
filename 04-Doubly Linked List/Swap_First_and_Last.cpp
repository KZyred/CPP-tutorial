#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
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
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
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
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This is the swapFirstLast function.               |
    //   | - It swaps the values of the first and last nodes   |
    //   |   in the doubly linked list.                        |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Check if the list has less than 2 nodes. If so,   |
    //   |   just return; nothing to swap.                     |
    //   | - Use a temporary variable to store the value of    |
    //   |   the head node.                                    |
    //   | - Assign the value of the tail node to the head     |
    //   |   node.                                             |
    //   | - Assign the stored head node value to the tail.    |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void swapFirstLast()
    {
        if (length < 2)
            return;
        int valueTemp = head->value;
        head->value = tail->value;
        tail->value = valueTemp;
    }
    void reverse()
    {
        if (length < 2)
        {
            return;
        }
        else
        {
            Node *current = head;
            Node *temp = nullptr;
            while (current)
            {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
            temp = head;
            head = tail;
            tail = temp;
        }
    }

    bool isPalindrome()
    {
        if (length == 1)
            return true;
        int len = length / 2;
        Node *curHead = head;
        Node *curTail = tail;
        while (len != 0)
        {
            if (curHead->value != curTail->value)
            {
                return false;
            }
            curHead = curHead->next;
            curTail = curTail->prev;
            len--;
        }
        return true;
    }
};
