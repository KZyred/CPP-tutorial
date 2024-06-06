#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinarySearchTree.cpp"

using namespace std;

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+

// DO NOT MAKE CHANGES TO CAPTUREOUTPUT FUNCTION //
inline string captureOutput(function<void()> func)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(sbuf);
    return buffer.str();
}

static void test()
{

    {
        cout << "\n----- Test: Single Node BST -----\n";
        BinarySearchTree tree;
        std::string output = captureOutput([&]()
                                           {
            tree.insert(10);
            tree.DFSInOrder(); });
        cout << "EXPECTED: 10 \n";
        cout << "RETURNED: " << output << "\n";
        cout << (output == "10 " ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Multiple Nodes BST -----\n";
        BinarySearchTree tree;
        std::string output = captureOutput([&]()
                                           {
            tree.insert(10);
            tree.insert(5);
            tree.insert(20);
            tree.DFSInOrder(); });
        cout << "EXPECTED: 5 10 20 \n";
        cout << "RETURNED: " << output << "\n";
        cout << (output == "5 10 20 " ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Full Tree BST -----\n";
        BinarySearchTree tree;
        std::string output = captureOutput([&]()
                                           {
            tree.insert(10);
            tree.insert(5);
            tree.insert(20);
            tree.insert(3);
            tree.insert(7);
            tree.insert(15);
            tree.insert(25);
            tree.DFSInOrder(); });
        cout << "EXPECTED: 3 5 7 10 15 20 25 \n";
        cout << "RETURNED: " << output << "\n";
        cout << (output == "3 5 7 10 15 20 25 " ? "PASS\n" : "FAIL\n");
    }
}

int main()
{
    test();
}