#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

vector<int> subarraySum(const vector<int> &nums, int target);

vector<int> subarraySum(const vector<int> &nums, int target)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds a subarray in 'nums' that     |
    //   |   sums up to the given 'target'.                    |
    //   | - It uses an unordered_map for quick look-up.       |
    //   | - It returns the indices of the start and end       |
    //   |   elements of the subarray.                         |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'sumIndex' stores cumulative sums and their       |
    //   |   indices.                                          |
    //   | - 'currentSum' keeps track of the sum up to index i.|
    //   | - Use 'find' method for quick look-up in map.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    // phải là liên tiếp
    unordered_map<int, int> sumIndex;
    int currentSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if (sumIndex.find(currentSum - target) != sumIndex.end())
        {
            return {sumIndex[target - currentSum] + 1, i};
        }
        else if (currentSum == target)
        {
            return {0, i};
        }
        sumIndex[currentSum] = i; // sum chắc chắn khác nhau ?, không nếu âm có thể giống nhau
    }
    return {};
}

// cách 2
vector<int> subarraySum2(const vector<int> &nums, int target)
{
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if (sumIndex.find(currentSum - target) != sumIndex.end())
        {
            return {sumIndex[currentSum - target] + 1, i};
        }
        sumIndex[currentSum] = i;
    }

    return {};
}
