#include <iostream>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[midIndex + 1 + j];

    int i = 0;
    int j = 0;
    int index = leftIndex;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function sorts an array using Merge Sort.    |
    //   | - It's a divide-and-conquer algorithm.              |
    //   | - First, it divides the array into halves.          |
    //   | - Then, it sorts each half.                         |
    //   | - Finally, it merges the sorted halves.             |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'midIndex' is calculated to divide the array.     |
    //   | - The function is recursive.                        |
    //   | - It calls itself for each half of the array.       |
    //   | - Then it calls 'merge' to merge sorted halves.     |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    if (leftIndex >= rightIndex)
        return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    // recursive for the left subarray
    mergeSort(array, leftIndex, midIndex);
    // right subarray
    mergeSort(array, midIndex + 1, rightIndex);
    merge(array, leftIndex, midIndex, rightIndex);
}
