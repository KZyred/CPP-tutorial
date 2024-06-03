#include <iostream>
#include "main.cpp"

using namespace std;

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+

static void test()
{

    {
        cout << "\n----- Test: Contains in Empty Tree -----\n";
        BinarySearchTree bst;
        int valueToSearch = 42;
        cout << "Searching for value " << valueToSearch << " in an empty tree - EXPECTED: false\n";
        cout << (bst.contains(valueToSearch) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: Contains with One Element -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        cout << "Inserting 10, then checking if it's contained - EXPECTED: true\n";
        cout << (bst.contains(10) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 5 - EXPECTED: false\n";
        cout << (bst.contains(5) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: Contains with Multiple Elements -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        cout << "Inserting 10, 5, 15, then checking if they're contained - EXPECTED: true\n";
        cout << (bst.contains(10) && bst.contains(5) && bst.contains(15) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 1 - EXPECTED: false\n";
        cout << (bst.contains(1) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: Contains with Duplicate Insert -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        bst.insert(10); // Duplicate insert
        cout << "Inserting 10 twice, then checking if it's contained - EXPECTED: true\n";
        cout << (bst.contains(10) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 15 - EXPECTED: false\n";
        cout << (bst.contains(15) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: Contains with Complex Structure -----\n";
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        cout << "Inserting 50, 30, 70, 20, 40, 60, 80, then checking if they're contained - EXPECTED: true\n";
        cout << (bst.contains(50) && bst.contains(30) && bst.contains(70) && bst.contains(20) && bst.contains(40) && bst.contains(60) && bst.contains(80) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 10 - EXPECTED: false\n";
        cout << (bst.contains(10) ? "FAIL\n" : "PASS\n");
    }
}

int main()
{
    test();
}