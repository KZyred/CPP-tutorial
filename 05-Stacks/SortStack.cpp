#include "SortStack.h"

void sortStack(stack<int> &inputStack)
{
    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+
    stack<int> additionalStack;
    while (!inputStack.empty())
    {
        int temp = inputStack.top();
        inputStack.pop();
        while (!additionalStack.empty())
        {
            if (additionalStack.top() > temp)
            {
                inputStack.push(additionalStack.top());
            }
        }
        additionalStack.push(temp);
    }
    while (!additionalStack.empty())
    {
        int temp = additionalStack.top();
        additionalStack.pop();
        inputStack.push(temp);
    }
}
