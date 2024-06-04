#include <vector>
#include <unordered_set>
using namespace std;

std::vector<vector<int>> findPairs(
    const vector<int> &arr1,
    const vector<int> &arr2,
    int target);

vector<vector<int>> findPairs(const vector<int> &arr1, const vector<int> &arr2, int target)
{
    //   +=========================================================+
    //   |                 WRITE YOUR CODE HERE                    |
    //   | Description:                                            |
    //   | - This function finds all pairs of integers from        |
    //   |   'arr1' and 'arr2' that sum up to 'target'.            |
    //   | - It uses an unordered_set for quick look-up.           |
    //   | - It returns a 2D vector containing the pairs.          |
    //   |                                                         |
    //   | Return type: vector<vector<int>>                        |
    //   |                                                         |
    //   | Tips:                                                   |
    //   | - 'mySet' stores numbers from 'arr1'.                   |
    //   | - 'pairs' will store the pairs that meet the target.    |
    //   | - Loop through 'arr1' to populate 'mySet'.              |
    //   | - Loop through 'arr2' to find pairs.                    |
    //   | - Use 'find' method for quick look-up in set.           |
    //   | - Check output from Test.cpp in "User logs".            |
    //   +=========================================================+
    vector<vector<int>> result;
    unordered_set<int> mySet;
    for (auto c : arr1)
    {
        mySet.insert(c);
    }
    for (auto c : arr2)
    {
        if (mySet.find(target - c) != mySet.end())
        {
            result.push_back({c, target - c});
        }
    }
    return result;
}