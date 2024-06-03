#include <unordered_map>
#include <vector>

using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2);

bool itemInCommon(vector<int> vect1, vector<int> vect2)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if two vectors have a        |
    //   |   common element.                                   |
    //   | - It uses an unordered_map to store elements from   |
    //   |   the first vector.                                 |
    //   | - Then it checks each element from the second       |
    //   |   vector against the map.                           |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'myMap' stores elements from 'vect1' as keys.     |
    //   | - Loop through 'vect2' and check against 'myMap'.   |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_map<int, bool> myMap;
    for (auto c : vect1)
    {
        myMap[c] = true;
    }
    for (auto c : vect2)
    {
        if (myMap[c] == true)
            return true;
    }
    return false;
}