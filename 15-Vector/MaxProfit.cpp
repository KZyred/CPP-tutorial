#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int maxProfit2(vector<int> &prices)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function calculates the maximum profit       |
    //   |   from buying and selling a stock.                  |
    //   | - It iterates through the 'prices' array once.      |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'minPrice' keeps track of the lowest price.       |
    //   | - 'maxProfit' stores the maximum profit found.      |
    //   | - Use 'min' and 'max' functions to update values.   |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    // tìm số bé nhất ở dãy đầu
    // số lớn nhất ở dãy sau
    // trả về hiệu là ra lợi nhuận

    int maxProfit = 0;
    if (prices.size() >= 1)
    {
        int min = prices.front();
        int max = prices.front();
        int indexMin = 0;
        int indexMax = 0;
        // tìm số bé nhất, tìm số lớn nhất -> O(n)
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
                indexMin = i;
            }
        }
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] > max)
            {
                max = prices[i];
                indexMax = i;
            }
        }
        if (indexMax > indexMin)
        {
            maxProfit = max - min;
        }
        else if (indexMax < indexMin)
        {
            for (int i = indexMin; i < prices.size(); i++)
            {
                if (prices[i] - min > maxProfit)
                {
                    maxProfit = prices[i] - min;
                }
            }
            for (int i = 0; i < indexMax; i++)
            {
                if (max - prices[i] > maxProfit)
                {
                    maxProfit = max - prices[i];
                }
            }
        }
    }
    return maxProfit;
}

// lời giải theo đáp án
// hay hơn
// giải thích:
// 1. tìm giá trị bé nhất theo cái mảng trước đó
// 2. trừ đi để ra lợi nhuận nhỏ nhất theo trước đó

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        int profit = price - minPrice;
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}
