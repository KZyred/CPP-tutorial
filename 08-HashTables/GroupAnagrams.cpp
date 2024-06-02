#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strings);

vector<vector<string>> groupAnagrams(const vector<string> &strings)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function groups anagrams from a given vector |
    //   |   of strings.                                       |
    //   | - It uses an unordered_map for organization.        |
    //   | - It sorts each string to form a canonical version. |
    //   | - Groups strings with the same canonical form.      |
    //   |                                                     |
    //   | Return type: vector<vector<string>>                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'anagramGroups' maps canonical strings to groups. |
    //   | - 'canonical' is a sorted version of each string.   |
    //   | - 'result' holds the final groups of anagrams.      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_map<int, vector<string>> anagramGroups;
    vector<vector<string>> result;
    for (auto sti : strings)
    {
        int asciiValue = 0;
        for (auto c : sti)
        {
            asciiValue += int(c);
        }
        anagramGroups[asciiValue].push_back(sti);
    }
    for (auto c : anagramGroups)
    {
        result.push_back(c.second);
    }
    return result;
}

// cách 2:
vector<vector<string>> groupAnagrams(const vector<string> &strings)
{
    unordered_map<string, vector<string>> anagramGroups;

    for (const string &str : strings)
    {
        string canonical = str;
        sort(canonical.begin(), canonical.end());

        anagramGroups[canonical].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto &group : anagramGroups)
    {
        result.push_back(group.second);
    }

    return result;
}