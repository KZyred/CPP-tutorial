#include <vector>
#include <unordered_set>

std::vector<int> removeDuplicates(const std::vector<int> &myList);

#include <vector>
#include <unordered_set>

using namespace std;

vector<int> removeDuplicates(const vector<int> &myList)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes duplicate integers from a   |
    //   |   given vector 'myList'.                            |
    //   | - It uses an unordered_set for quick look-up and    |
    //   |   elimination of duplicates.                        |
    //   | - Returns a vector of unique integers.              |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'uniqueSet' stores unique numbers from 'myList'.  |
    //   | - Use 'begin()' and 'end()' to copy elements back   |
    //   |   to a vector.                                      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    unordered_set<int> uniqueSet;
    vector<int> result;
    for (auto c : myList)
    {
        uniqueSet.insert(c);
    }
    for (auto it = uniqueSet.begin(); it != uniqueSet.end(); ++it)
        result.push_back(*it);
    return result;
}