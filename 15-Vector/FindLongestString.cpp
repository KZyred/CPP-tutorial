#include <string>
#include <vector>

using namespace std;

string findLongestString(vector<string> &stringList)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest string in         |
    //   |   a given list of strings.                          |
    //   | - It uses a single loop to check the length         |
    //   |   of each string.                                   |
    //   |                                                     |
    //   | Return type: string                                 |
    //   | - Returns the longest string found in the list.     |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'longestString' keeps track of the longest        |
    //   |   string found so far.                              |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    string longestString = "";
    if (stringList.size() >= 1)
    {
        longestString = stringList[0];
        for (string &string : stringList)
        {
            if (string.length() > longestString.length())
                longestString = string;
        }
    }
    return longestString;
}

// lời giải theo đáp án
string findLongestString(vector<string> &stringList)
{
    string longestString = "";
    for (const string &str : stringList)
    {
        if (str.length() > longestString.length())
        {
            longestString = str;
        }
    }
    return longestString;
}
