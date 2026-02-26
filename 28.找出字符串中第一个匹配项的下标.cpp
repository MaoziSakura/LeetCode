/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
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

using namespace std;

// @lc code=start

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int index = -1;
        bool flag = false;
        for (int i = 0 ; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                flag = true;
                for (int j = 1; j < needle.size(); j++)
                {
                    if (i + j >= haystack.size() || haystack[i + j] != needle[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                index = i;
                break;
            }
        }
        return index;
    }
};
// @lc code=end

