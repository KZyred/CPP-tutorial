#include <vector>

using namespace std;

vector<int> findMaxMin(vector<int> &myList)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the maximum and minimum       |
    //   |   values in a given list of integers.               |
    //   | - It uses a single loop to go through the list.     |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   | - Returns a vector containing maximum and minimum.  |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'maximum' and 'minimum' keep track of the         |
    //   |   highest and lowest values found.                  |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    vector<int> result;
    int maximum = myList.front();
    int minimum = myList.front();
    for (int c : myList)
    {
        if (maximum < c)
            maximum = c;
        if (minimum > c)
            minimum = c;
    }
    result.push_back(maximum);
    result.push_back(minimum);
    return result;
}

// lời giải theo đáp án
vector<int> findMaxMin(vector<int> &myList)
{
    int maximum = myList[0];
    int minimum = myList[0];
    for (int num : myList)
    {
        if (num > maximum)
        {
            maximum = num;
        }
        else if (num < minimum)
        {
            minimum = num;
        }
    }
    return vector<int>{maximum, minimum};
}