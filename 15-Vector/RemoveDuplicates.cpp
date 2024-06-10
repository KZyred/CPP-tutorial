#include <vector>
#include <unordered_set>

using namespace std;

int removeDuplicates2(vector<int> &nums)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes duplicate integers          |
    //   |   from a sorted array in-place.                     |
    //   | - It uses two pointers to achieve this.             |
    //   |                                                     |
    //   | Return type: int                                    |
    //   | - Returns the length of the new array.              |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'writePointer' is used for storing unique values. |
    //   | - 'readPointer' is used for reading array values.   |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    int length = 0;
    int i = 0;
    int j = i + 1;
    while (i < nums.size())
    {
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
            {
                i--;
                nums.erase(nums.begin() + j);
            }
            else
            {
                j++;
            }
        }
        i++;
        j = i + 1;
    }
    length = nums.size();
    return length;
}

// lời giải theo đáp án
// nhận xét: phần lời giải này ko remove gì cả,
// chỉ là mẹo:
// 1. xếp lại mảng các phần tử không trùng lặp lên phía trước
// 2. và trả ra độ dài mảng
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int writePointer = 1;

    for (int readPointer = 1; readPointer < nums.size(); readPointer++)
    {
        if (nums[readPointer] != nums[readPointer - 1])
        {
            nums[writePointer] = nums[readPointer];
            writePointer++;
        }
    }

    return writePointer;
}