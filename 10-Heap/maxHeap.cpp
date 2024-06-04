#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2; // do bị dịch chuyển sang phải 1
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
    //   | - Inserts a new value into the heap.              |
    //   | - Maintains the heap's property by ensuring the   |
    //   |   newly inserted element is moved to its          |
    //   |   correct position in the heap.                   |
    //   |                                                   |
    //   | Parameters:                                       |
    //   | - value: The value to be inserted into the heap.  |
    //   |                                                   |
    //   | Behavior:                                         |
    //   | - The value is added to the end of the heap.      |
    //   | - The method then compares the added value with   |
    //   |   its parent node, swapping them if necessary to  |
    //   |   maintain the heap property.                     |
    //   | - This comparison and potential swap continue     |
    //   |   until the heap property is restored or the      |
    //   |   added node becomes the root of the heap.        |
    //   +===================================================+
    // cách 1: không thành công
    void insert2(int value)
    {
        if (heap.empty())
        {
            heap.push_back(value);
        }
        else
        {
            for (int i = 0; i < heap.size(); i++)
            {
                if (heap[i] < value)
                {
                    int temp = heap[i];
                    heap[i] = value;
                    value = temp;
                }
            }
            heap.push_back(value);
        }
    }
    // cách 2: tham khảo đáp án
    void insert(int value)
    {
        // tóm tắt:
        // 1. thêm vào cuối
        // 2. tìm cha thằng cuối
        // 3. so sánh lớn hơn thì đổi chỗ cho nhau

        // 1. trước hết cứ push xuống cuối
        heap.push_back(value);
        // 2. sau đó sắp xếp lại vector
        // dòng này sẽ tính chỉ số của nó trong mảng.
        // Vì việc lập chỉ mục mảng bắt đầu từ 0
        // nên chỉ mục của phần tử cuối cùng luôn nhỏ hơn kích thước của mảng một đơn vị.
        // Chỉ mục này được lưu trữ ở dạng hiện tại,
        // chúng tôi sẽ sử dụng chỉ mục này để theo dõi vị trí của phần tử mới được thêm vào
        // khi chúng tôi có thể di chuyển nó lên vùng nhớ heap.
        int current = heap.size() - 1;
        /**
         * current > 0: đảm bảo phần tử mới thêm vào không phải là phần tử gốc, do index = 0: root
         * heap[current] > heap[parent(current)]: kiểm tra xem phần tử hiện tại có lớn hơn nút cha của nó không
         */
        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current)); // thay đổi giá trị hai phần tử trong mảng, hàm viết sẵn
            current = parent(current);      // cập nhật lại index
        }
    }
};
