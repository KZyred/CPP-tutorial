#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function sorts an array using the            |
    //   |   Insertion Sort algorithm.                         |
    //   | - It iterates through 'array[]' to place each       |
    //   |   element in its correct position.                  |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'temp' holds the current element being examined.  |
    //   | - 'j' is used to find the correct position for      |
    //   |   'temp'.                                           |
    //   | - 'array[j+1]' and 'array[j]' are swapped as needed.|
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
            else
            {
                break; // quan trọng
            }
        }
    }
}

// cách 2: theo đáp án

void insertionSort2(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j > -1 && temp < array[j])
        {
            array[j + 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}