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
private:
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

    bool rContains(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return false;

        if (currentNode->value == value)
            return true;

        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else
        {
            return rContains(currentNode->right, value);
        }
    }
    bool rContains(int value)
    {
        return rContains(root, value);
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

    //   +===================================================+
    //   |              WRITE YOUR CODE HERE                 |
    //   | Description:                                      |
    //   | - Recursively inserts a new node with a given     |
    //   |   value into a binary search tree.                |
    //   |                                                   |
    //   | Parameters:                                       |
    //   | - currentNode: The node currently being examined. |
    //   | - value: The value to insert into the tree.       |
    //   |                                                   |
    //   | Return:                                           |
    //   | - Returns the node itself if it is not null.      |
    //   | - If a null node is encountered, it creates and   |
    //   |   returns a new node with the given value,        |
    //   |   effectively inserting it into the tree.         |
    //   |                                                   |
    //   | Behavior:                                         |
    //   | - The function traverses the tree starting from   |
    //   |   the currentNode.                                |
    //   | - Based on the value to be inserted, it explores  |
    //   |   the left or right subtree.                      |
    //   | - Insertion is done only if the correct position  |
    //   |   (a null spot) in the tree is found, maintaining |
    //   |   the BST property.                               |
    //   | - The tree's structure is unaltered if the value  |
    //   |   already exists in the tree.                     |
    //   +===================================================+

    void rInsert(int value)
    {
        if (root == nullptr)
            root = new Node(value);
        rInsert(root, value);
    }
    // cách 1: dài dòng, tự tư duy
    Node *rInsert1(Node *currentNode, int value)
    {
        if (currentNode->value == value)
            return nullptr;
        if (currentNode->value > value)
        {
            if (currentNode->left == nullptr)
            {
                currentNode->left = new Node(value);
                return currentNode;
            }
            return rInsert(currentNode->left, value);
        }
        else
        {
            if (currentNode->right == nullptr)
            {
                currentNode->right = new Node(value);
                return currentNode;
            }
            return rInsert(currentNode->right, value);
        }
    }
    // cách 2: ngắn ngon tham khảo
    Node *rInsert(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return new Node(value);

        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }
    /**
     * Tìm giá trị nhỏ nhất
     */
    int minValue(Node *currentNode)
    {
        if (currentNode->left == nullptr)
            return currentNode->value;
        return minValue(currentNode->left);
    }
    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }
    /**
     * loại bỏ một node cụ thể trong tree
     */
    Node *deleteNode_faulTwoChild(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return nullptr;
        }
        if (currentNode->value > value)
        {
            return deleteNode(currentNode->left, value); // sai
        }
        else if (currentNode->value < value)
        {
            return deleteNode(currentNode->right, value); // sai
        }
        Node *temp = currentNode;
        if (currentNode->left == nullptr && currentNode->right == nullptr) // leaf
        {
        }
        else if (currentNode->left != nullptr && currentNode->right != nullptr)
        { // 2 con
            // hãy tìm giá trị tối thiểu trong cây con bên phải (để duy trì thuộc tính BST),
            // thay thế giá trị của nút cần xóa bằng giá trị tối thiểu này,
            // sau đó xóa đệ quy nút ban đầu có giá trị này giá trị nhỏ nhất ở cây con bên phải.
            currentNode->value = minValue(currentNode->right);
            return deleteNode(currentNode->right, currentNode->value); // sai
        }
        else if (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
            delete temp;
            return currentNode;
        }
        else if (currentNode->right != nullptr)
        {
            currentNode = currentNode->right;
            delete temp;
            return currentNode;
        }
        delete temp;
        return nullptr;
    }
    // cần trả về root, chưa tìm được cách
    // cơ bản logic ok rùi

    Node *deleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr;

        if (value < currentNode->value)
        {
            currentNode->left = deleteNode(currentNode->left, value); //*
        }
        else if (value > currentNode->value)
        {
            currentNode->right = deleteNode(currentNode->right, value); //*
        }
        else
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                delete (currentNode);
                return nullptr;
            }
            else if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete (currentNode);
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                Node *temp = currentNode->left;
                delete (currentNode);
                return temp;
            }
            else
            {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin); //*
            }
        }
        return currentNode;
    }
};
