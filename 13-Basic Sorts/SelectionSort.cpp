#include <iostream>
using namespace std;
void selectionSort(int array[], int size)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function sorts an array using the            |
    //   |   Selection Sort algorithm.                         |
    //   | - It finds the minimum element and swaps it with    |
    //   |   the first element, then repeats for the remaining.|
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'minIndex' holds the index of the smallest        |
    //   |   element found.                                    |
    //   | - 'temp' is used for swapping elements.             |
    //   | - Swap only if 'i' and 'minIndex' are different.    |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}