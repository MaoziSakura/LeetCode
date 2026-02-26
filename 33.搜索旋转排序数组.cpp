/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int>& nums, int target) 
    {
        int break_num = -1;
        int result = -1;
        for (int i = 0; i < nums.size(); i++)    
        {
            if (i + 1 < nums.size() && nums[i] > nums[i + 1])
                break_num = i;
        }
        if (break_num != -1)
        {
            int value_one = lower_bound(nums.begin(), nums.begin() + break_num, target) - nums.begin();
            int value_two = lower_bound(nums.begin() + break_num + 1, nums.end(), target) - nums.begin();
            if (value_one < nums.size() && nums[value_one] == target)
                result = value_one;
            if (value_two < nums.size() && nums[value_two] == target)
                result = value_two;
        }
        else
        {
            int value = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if (value < nums.size() && nums[value] == target)
                result = value;
        }
        return result;
    }
};
// @lc code=end

