#include <string>
#include <unordered_set>

bool hasUniqueChars(const std::string &str);
#include <string>
#include <unordered_set>

using namespace std;

bool hasUniqueChars(const string &str)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if a string 'str' has unique |
    //   |   characters.                                       |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - It returns a boolean value.                       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'charSet' stores characters we've seen.           |
    //   | - Loop through 'str' to populate 'charSet'.         |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - If a duplicate is found, return false.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_set<char> charSet;
    for (auto c : str)
    {
        if (charSet.find(c) != charSet.end())
        {
            return false;
        }
        charSet.insert(c);
    }
    return true;
}