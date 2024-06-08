#include <iostream>
#include <algorithm> // for std::is_sorted
using namespace std;

void swap(int array[], int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex)
{
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++)
    {
        if (array[i] < array[pivotIndex])
        {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function sorts an array using Quick Sort.    |
    //   | - It sorts the part of array between 'leftIndex'    |
    //   |   and 'rightIndex'.                                 |
    //   | - The function is recursive, calling itself to      |
    //   |   sort the left and right partitions.               |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'pivotIndex' is the index of the pivot after      |
    //   |   partitioning.                                     |
    //   | - The function calls itself recursively to sort     |
    //   |   sub-arrays.                                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    if (leftIndex >= rightIndex)
        return;
    int pivotIndex = pivot(array, leftIndex, rightIndex); // trả ra pivot, đồng thời hàm biến đổi array thành array pivot ở trung tâm
    quickSort(array, leftIndex, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, rightIndex);
}
