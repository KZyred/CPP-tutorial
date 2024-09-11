#include <iostream>


// Trường Hợp Tốt Nhất với Cải Tiến:
// Để cải thiện độ phức tạp thời gian trong trường hợp tốt nhất, thuật toán Bubble Sort có thể được tối ưu hóa bằng cách sử dụng một cờ (flag). Cải tiến này hoạt động như sau:

// 1. Thêm một Biến Cờ:
// Thêm một biến boolean gọi là swapped để theo dõi xem có phần tử nào bị hoán đổi trong vòng lặp hiện tại hay không.

// 2. Kiểm Tra Sau Mỗi Vòng Lặp:
// Trong mỗi vòng lặp, kiểm tra nếu không có phần tử nào bị hoán đổi. Nếu không có phần tử nào bị hoán đổi trong một vòng lặp, có nghĩa là dãy đã được sắp xếp và thuật toán có thể dừng lại sớm.

// Giải Thích Độ Phức Tạp Thời Gian Tốt Nhất:
// - Trường hợp tốt nhất: Khi dãy đã được sắp xếp sẵn, biến swapped sẽ luôn giữ giá trị false sau mỗi vòng lặp qua toàn bộ dãy.
// - Tối ưu hóa: Trong trường hợp này, thuật toán chỉ cần một lần lặp qua dãy dữ liệu mà không cần thực hiện bất kỳ phép hoán đổi nào. Do đó, số lần lặp qua dãy chỉ là một lần (n), và độ phức tạp thời gian là 𝑂(𝑛).

using namespace std;
void bubbleSort(int array[], int size)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function sorts an array using the            |
    //   |   Bubble Sort algorithm.                            |
    //   | - It compares adjacent elements and swaps them if   |
    //   |   they're in the wrong order.                       |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'temp' is used for swapping elements.             |
    //   | - The outer loop decreases in size each iteration.  |
    //   | - Inner loop iterates up to 'i'.                    |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
// cách 2: lời giải gốc
void bubbleSort(int array[], int size)
{
    for (int i = size - 1; i > 0; i--) // giảm từ cuối
    {
        for (int j = 0; j < i; j++) // lặp qua sub array
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
