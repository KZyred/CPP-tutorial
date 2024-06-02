#include "ReverseString.h"

string reverseString(const string &str)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    stack<char> charStack;
    string reverseString = "";
    for (auto c : str)
    {
        charStack.push(c);
    }
    while (!charStack.empty())
    {
        reverseString += charStack.top();
        charStack.pop();
    }
    return reverseString;
}
