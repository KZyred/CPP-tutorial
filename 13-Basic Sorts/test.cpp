#include <iostream>
#include "BubbleSort.cpp"

using namespace std;

bool isSorted(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void printArray(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void test()
{
    {
        cout << "\n----- Test: EmptyArray -----\n";
        int arr[] = {};
        cout << "Original Array: ";
        printArray(arr, 0);
        cout << "\n";
        bubbleSort(arr, 0);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 0) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 0) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SingleElementArray -----\n";
        int arr[] = {42};
        cout << "Original Array: ";
        printArray(arr, 1);
        cout << "\n";
        bubbleSort(arr, 1);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 1) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 1) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: AlreadySortedArray -----\n";
        int arr[] = {1, 2, 3, 4, 5};
        cout << "Original Array: ";
        printArray(arr, 5);
        cout << "\n";
        bubbleSort(arr, 5);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 5) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 5) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: ReverseSortedArray -----\n";
        int arr[] = {5, 4, 3, 2, 1};
        cout << "Original Array: ";
        printArray(arr, 5);
        cout << "\n";
        bubbleSort(arr, 5);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 5) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 5) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: RandomArray -----\n";
        int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        cout << "Original Array: ";
        printArray(arr, 11);
        cout << "\n";
        bubbleSort(arr, 11);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 11) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 11) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: DuplicatesArray -----\n";
        int arr[] = {3, 3, 3, 1, 2, 2, 2};
        cout << "Original Array: ";
        printArray(arr, 7);
        cout << "\n";
        bubbleSort(arr, 7);
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (isSorted(arr, 7) ? "true" : "false") << "\n";
        cout << (isSorted(arr, 7) ? "PASS\n" : "FAIL\n");
    }
}

int main()
{
    test();
}