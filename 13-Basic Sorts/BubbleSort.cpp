#include <iostream>

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