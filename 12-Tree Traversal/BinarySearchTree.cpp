#include <iostream>
#include <queue>

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
private:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    // ---------------------------------------------------
    //  This is a helper function used by the destructor
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

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
                return false;
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method performs a Breadth-First Search       |
    //   |   (BFS) starting from the root of the tree.         |
    //   | - Prints the value of each node as it visits it.    |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses a queue (myQueue) to keep track of nodes     |
    //   |   to visit.                                         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void BFS()
    {
        queue<Node *> myQueue;
        if (root != nullptr)
        {
            myQueue.push(root);
        }
        while (!myQueue.empty())
        {
            Node *currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left != nullptr)
            {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                myQueue.push(currentNode->right);
            }
        }
    }
    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method performs a Depth-First Search         |
    //   |   (DFS) using Pre-Order traversal.                  |
    //   | - Starts at the given 'currentNode' and goes        |
    //   |   down its children.                                |
    //   | - Prints the value of each node as it visits it.    |
    //   | - Root -> Left -> Right                             |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses recursion for traversal.                     |
    //   | - Base case returns if currentNode is null.         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void DFSPreOrder()
    {
        DFSPreOrder(root);
    }
    void DFSPreOrder(Node *currentNode)
    {
        cout << currentNode->value << " ";
        if (currentNode->left != nullptr)
            DFSPreOrder(currentNode->left);
        if (currentNode->right != nullptr)
            DFSPreOrder(currentNode->right);
    }
    // void DFSPreOrder()
    // {
    //     Node *currentNode = root;
    //     while (currentNode != nullptr && currentNode->left != nullptr )
    //     {
    //         cout << currentNode->value << " ";
    //         if (currentNode->left != nullptr)
    //         {
    //             currentNode = currentNode->left;
    //         }
    //         if (currentNode->right != nullptr)
    //         {
    //             currentNode = currentNode->right;
    //         }
    //     }
    // }

    //   +=====================================================+
    //   |                    WRITE YOUR CODE HERE             |
    //   | Description:                                        |
    //   | - This method performs a Depth-First Search         |
    //   |   (DFS) using Post-Order traversal.                 |
    //   | - Starts at the given 'currentNode' and goes        |
    //   |   down its children before printing its value.      |
    //   | - Left -> Right -> Root                             |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses recursion for traversal.                     |
    //   | - Base case returns if currentNode is null.         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void DFSPostOrder()
    {
        DFSPostOrder(root);
    }
    void DFSPostOrder(Node *currentNode)
    {
        if (currentNode->left != nullptr)
            DFSPostOrder(currentNode->left);
        if (currentNode->right != nullptr)
            DFSPostOrder(currentNode->right);
        cout << currentNode->value << " ";
    }

    //   +=====================================================+
    //   |                    WRITE YOUR CODE HERE             |
    //   | Description:                                        |
    //   | - This method performs a Depth-First Search         |
    //   |   (DFS) using In-Order traversal.                   |
    //   | - Starts at the given 'currentNode' and traverses   |
    //   |   the left subtree, then the current node, then the |
    //   |   right subtree.                                    |
    //   | - Left -> Root -> Right                             |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses recursion for traversal.                     |
    //   | - Checks for null pointers before recursive calls.  |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void DFSInOrder()
    {
        DFSInOrder(root);
    }
    void DFSInOrder(Node *currentNode)
    {
        if (currentNode->left != nullptr)
            DFSInOrder(currentNode->left);
        cout << currentNode->value << " ";
        if (currentNode->right != nullptr)
            DFSInOrder(currentNode->right);
    }
};
