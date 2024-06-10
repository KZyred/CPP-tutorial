#include <vector>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
void rotate(vector<int> &nums, int k)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function rotates the array 'nums' to the     |
    //   |   right by 'k' steps.                               |
    //   | - The method used involves reversing parts of the   |
    //   |   array.                                            |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'k' is first made smaller by taking modulo size.  |
    //   | - Three reversals are done to achieve the rotation. |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    // đẩy vector về phía bên phải: k lần
    vector<int> numsNew = nums;
    for (int j = 0; j < nums.size(); j++)
    {

        numsNew[(j + k) % nums.size()] = nums[j];
    }
    nums = numsNew;
}

// cách 2: theo lời giải
// chưa hình dung được cách xoay 3 lần của họ?
// time complexity: O(n)
// space complexity: O(1)
void rotate(vector<int> &nums, int k)
{
    if (nums.empty())
        return;

    k = k % nums.size();

    // Reverse the first part
    for (int start = 0, end = nums.size() - k - 1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // Reverse the second part
    for (int start = nums.size() - k, end = nums.size() - 1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // Reverse the whole array
    for (int start = 0, end = nums.size() - 1; start < end; start++, end--)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}