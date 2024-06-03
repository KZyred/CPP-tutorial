#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target);
vector<int> twoSum(const vector<int> &nums, int target)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds two numbers in 'nums' that    |
    //   |   sum up to the given 'target'.                     |
    //   | - It uses an unordered_map for quick look-up.       |
    //   | - It returns the indices of the numbers that add    |
    //   |   up to the target.                                 |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numMap' stores numbers and their indices.        |
    //   | - 'complement' is the value needed to reach target. |
    //   | - Use 'find' method for quick look-up in map.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int complement = target - num;

        if (numMap.find(complement) != numMap.end())
        {
            return {numMap[complement], i};
        }
        numMap[num] = i;
    }

    return {};
}