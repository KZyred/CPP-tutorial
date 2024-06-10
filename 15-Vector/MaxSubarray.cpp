#include <vector>
#include <algorithm>

using namespace std;

int maxSubarray(vector<int> &nums)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the sum of the contiguous     |
    //   |   subarray with the largest sum from the given      |
    //   |   array 'nums'.                                     |
    //   | - It uses Kadane's algorithm for this task.         |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'maxSum' stores the maximum subarray sum.         |
    //   | - 'currentSum' keeps track of the sum of the        |
    //   |   subarray ending at the current index.             |
    //   | - Use 'max' to update 'maxSum' and 'currentSum'.    |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    // tìm ra tổng lớn nhất của một chuỗi liên tiếp
    // mẹo ->
    // 1. cứ tính tịnh tiến -> tổng = tổng + liền trước
    // 2. lớn hơn -> đổi
    // 3. ấm thì current = 0
    if (nums.size() < 1)
        return 0;
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum = currentSum + nums[i];
        if (currentSum > maxSum)
            maxSum = currentSum;
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}