#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    // ---------------------------------------------------
    //  Below is a helper function used by the destructor
    //  Deletes all nodes in BST
    //  Similar to DFS PostOrder in Tree Traversal section
    // ---------------------------------------------------
    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    Node *getRoot()
    {
        return root;
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method inserts a new value into the tree.    |
    //   | - A new node is created for the value.              |
    //   | - Starts at root and finds the correct location.    |
    //   | - Return type: bool                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - If the tree is empty (root == nullptr), set root  |
    //   |   to the new node and return true.                  |
    //   | - Use a while loop to find the correct location.    |
    //   | - If the value already exists, return false.        |
    //   | - Insert the new node at the correct position.      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *tempVal = root;
            while (tempVal != nullptr)
            {
                if (tempVal->value > value)
                {
                    if (tempVal->left == nullptr)
                    {
                        tempVal->left = newNode;
                        return true;
                    }
                    tempVal = tempVal->left;
                }
                else if (tempVal->value < value)
                {
                    if (tempVal->right == nullptr)
                    {
                        tempVal->right = newNode;
                        return true;
                    }
                    tempVal = tempVal->right;
                }
                else if (tempVal->value == value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool contains(int value)
    {
        if (root != nullptr)
        {
            Node *tempVal = root;
            while (tempVal != nullptr)
            {
                if (tempVal->value > value)
                {
                    tempVal = tempVal->left;
                }
                else if (tempVal->value < value)
                {
                    tempVal = tempVal->right;
                }
                else if (tempVal->value == value)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
