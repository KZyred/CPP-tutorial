#include <iostream>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function merges two sorted arrays into one.  |
    //   | - It is a part of the Merge Sort algorithm.         |
    //   | - Takes three index values to divide the arrayTest.     |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'leftArray' and 'rightArray' are temp arrays.     |
    //   | - They store parts of the original arrayTest.           |
    //   | - 'i' and 'j' loop through these arrays.            |
    //   | - 'index' is for placing sorted elements back.      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i <= rightIndex; i++)
    {
        if (i <= midIndex)
            leftArray[i] = array[i];
        if (i > midIndex)
            rightArray[i - midIndex - 1] = array[i];
    }

    int index = 0, i = 0, j = 0;
    while (index != rightIndex + 1)
    {
        if (i == midIndex + 1)
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
        else if (j == rightIndex + 1)
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else if (leftArray[i] < rightArray[j])
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else if (leftArray[i] > rightArray[j])
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }
}