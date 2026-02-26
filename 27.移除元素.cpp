/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

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

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int last_index = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            while (last_index >= 0 && nums[last_index] == val)
                --last_index;
            if (i >= last_index)
                break;
            if (last_index < 0)
                break;
            if (nums[i] == val)
            {
                nums[i] = nums[last_index];
                nums[last_index] = val;
            }
        }
        return last_index + 1;
    }
};
// @lc code=end