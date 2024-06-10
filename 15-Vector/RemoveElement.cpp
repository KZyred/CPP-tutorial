#include <vector>

using namespace std;

void removeElement(vector<int> &nums, int val)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes all occurrences of a        |
    //   |   given value ('val') from an integer vector.       |
    //   | - It modifies the input vector 'nums'.              |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses two pointers 'i' and 'j' for traversal.      |
    //   | - 'i' points to the last element that is not 'val'. |
    //   | - 'j' is used for iterating over the array.         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

// lời giải theo đáp án
void removeElement(vector<int> &nums, int val)
{
    size_t i = 0;
    for (size_t j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    nums.resize(i);
}