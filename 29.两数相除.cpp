/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <unordered_set>
#include <stack>
#include <deque>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long a = dividend, b = divisor;
        int flag = 0;
        if (a < 0)
        {
            ++flag;
            a = -a;
        }
        if (b < 0)
        {
            ++flag;
            b = -b;
        }
        long long result = 0;
        while(a >= b)
        {
            if (b == 1)
            {
                result = a;
                break;
            }
            ++result;
            a -= b;
        }
        if (flag & 1)
            result = -result;
        if (result < INT_MIN)
            result = INT_MIN;
        if (result > INT_MAX)
            result = INT_MAX;
        return int(result);
    }
};
// @lc code=end

