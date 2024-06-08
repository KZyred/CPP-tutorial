#include <iostream>

using namespace std;

void swap(int array[], int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex)
{
    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function rearranges the array around a pivot. |
    //   | - It places the pivot in its sorted position.        |
    //   | - Elements smaller than the pivot move to its left.  |
    //   | - Elements greater than the pivot move to its right. |
    //   |                                                      |
    //   | Return type: int                                     |
    //   | - The index of the pivot after rearrangement.        |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - 'swapIndex' tracks where the next smaller element  |
    //   |   should go.                                         |
    //   | - Loop through the array and swap elements as        |
    //   |   needed.                                            |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++)
    {
        if (array[i] < array[pivotIndex])
        {
            swapIndex++;
            swap(array[i], array[swapIndex]);
        }
    }
    swap(array[pivotIndex], array[swapIndex]);
    return swapIndex;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}