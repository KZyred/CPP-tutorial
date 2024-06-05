#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    const vector<int> &getHeap() const
    {
        return heap;
    }

    //   +===================================================+
    //   |              WRITE YOUR CODE HERE                 |
    //   | Description:                                      |
    //   | - Inserts a new value into the min heap.          |
    //   | - Adjusts the heap to maintain the min heap       |
    //   |   property after the insertion.                   |
    //   |                                                   |
    //   | Parameters:                                       |
    //   | - value: The value to be inserted into the heap.  |
    //   |                                                   |
    //   | Behavior:                                         |
    //   | - The value is added to the end of the heap.      |
    //   | - The method then compares the added value with   |
    //   |   its parent, swapping them if the child is       |
    //   |   smaller, to maintain the min heap property.     |
    //   | - This comparison and potential swap continue     |
    //   |   until the new node is in its correct position   |
    //   |   or it becomes the root node.                    |
    //   +===================================================+
    void insert(int value)
    {
        heap.push_back(value);
        int iIns = heap.size() - 1;
        while (iIns > 0 && heap[iIns] < heap[parent(iIns)])
        {
            swap(parent(iIns), iIns);
            iIns = parent(iIns);
        }
    }

    void sinkDown(int index)
    {
        int minIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex])
            {
                minIndex = leftIndex;
            }

            if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex])
            {
                minIndex = rightIndex;
            }

            if (minIndex != index)
            {
                swap(index, minIndex);
                index = minIndex;
            }
            else
            {
                return;
            }
        }
    }

    int remove()
    {
        if (heap.size() < 1)
        {
            return INT_MAX;
        }
        int min = heap.front();
        swap(0, heap.size() - 1); // chuyển đổi dữ liệu
        heap.pop_back();          // loại ra
        sinkDown(0);
        return min;
    }
};
