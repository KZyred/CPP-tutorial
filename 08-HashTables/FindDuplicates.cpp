#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findDuplicates(const vector<int> &nums);

vector<int> findDuplicates(const vector<int> &nums)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds duplicate integers in a given |
    //   |   vector.                                           |
    //   | - It uses an unordered_map to count each integer's  |
    //   |   occurrences.                                      |
    //   | - Loops through the map to find duplicates.         |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numCounts' keeps track of each integer's count.  |
    //   | - 'duplicates' stores duplicate integers found.     |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    vector<int> duplicates;
    unordered_map<int, bool> map;
    for (auto c : nums)
    {
        if (map[c])
        {
            duplicates.push_back(c);
        }
        else
        {
            map[c] = true;
        }
    }
    return duplicates;
}

// cách 2:

vector<int> findDuplicates2(const vector<int> &nums)
{
    unordered_map<int, int> numCounts;
    for (int num : nums)
    {
        numCounts[num]++;
    }
    vector<int> duplicates;
    // first: key
    // second: value
    for (const auto &entry : numCounts) // đây là cách duyệt unordered_map
    {
        if (entry.second > 1)
        {
            duplicates.push_back(entry.first);
        }
    }
    return duplicates;
}