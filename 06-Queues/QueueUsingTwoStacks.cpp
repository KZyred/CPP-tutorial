#include <stack>
#include <climits>

using namespace std;

class QueueUsingTwoStacks
{
private:
    stack<int> stack1, stack2;

public:
    int front()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty())
        {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty()
    {
        return stack1.empty() && stack2.empty();
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void enqueue(int value)
    {
        stack1.push(value);
    }
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method removes a value from the front of the |
    //   |   queue (dequeue) using 'stack2'.                   |
    //   | - If 'stack2' is empty, it fills 'stack2' from      |
    //   |   'stack1'.                                         |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - If 'stack2' is empty, pop all elements from       |
    //   |   'stack1' into 'stack2'.                           |
    //   | - Then, pop the top element of 'stack2'.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void dequeue()
    {
        // không được check stack1 empty ở đây
        // do trong phần test-> front đã đảo giữa stack2 và stack1
        // -> stack1 auto empty
        // if (stack1.empty())
        // {
        //     return;
        // }
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (!stack2.empty())
        {
            stack2.pop();
        }
    }
};
