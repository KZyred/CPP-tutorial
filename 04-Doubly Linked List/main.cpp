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
    void makeEmpty()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
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
    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        length--;
        delete temp;
    }
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
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
            head->prev = nullptr;
        }
        length--;
        delete temp;
    }
    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp = head;
        while (index != 0)
        {
            temp = temp->next;
            index--;
        }

        return temp;
    }
    bool set(int index, int value)
    {
        if (index < 0 || index >= length)
            return false;
        Node *temp = get(index);
        temp->value = value;
        return true;
    }
    bool insert(int index, int value)
    {
        if (length == 0 && index != 0)
            return false;
        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepend(value);
        }
        else if (index == length)
        {
            append(value);
        }
        else
        {
            Node *temp = get(index - 1);
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            length++;
        }
        return true;
    }
    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            return;
        }
        if (index == 0)
        {
            deleteFirst();
        }
        else if (index == (length - 1))
        {
            deleteLast();
        }
        else
        {
            Node *temp = get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }
    }
};
