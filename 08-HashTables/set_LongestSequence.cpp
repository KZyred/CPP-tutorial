#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutiveSequence(const std::vector<int> &nums);
int longestConsecutiveSequence(const vector<int> &nums)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest consecutive       |
    //   |   sequence of integers in a given array.            |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - Loop through each unique number in the set.       |
    //   | - For each number, check its sequence length.       |
    //   | - Update 'longestStreak' if a longer sequence is    |
    //   |   found.                                            |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numSet' stores unique numbers from 'nums'.       |
    //   | - 'longestStreak' keeps track of the longest        |
    //   |   sequence found so far.                            |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_set<int> numSet;
    int longestStreak = 1;

    if (nums.size() < 1) // empty
    {
        return 0;
    }

    for (auto c : nums)
    {
        numSet.insert(c);
    }

    for (auto num : numSet)
    {
        int currentStreak = 1;
        while (numSet.find(num + 1) != numSet.end())
        {
            currentStreak++;
            num++;
        }
        longestStreak = max(currentStreak, longestStreak);
    }
    return longestStreak;
}

int longestConsecutiveSequence2(const vector<int> &nums)
{
    unordered_set<int> numSet;
    int longestStreak = 0;
    // auto unique
    for (auto c : nums)
    {
        numSet.insert(c);
    }
    for (auto num : numSet)
    {
        // tìm số nhỏ hơn liền kề
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentStreak = 1;
            // tìm số lớn hơn liền kề
            while (numSet.find(currentNum + 1) != numSet.end())
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
