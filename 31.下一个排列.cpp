/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int>& nums) 
    {
        int last_index = nums.size() - 1;
        while (last_index - 1 >= 0 && nums[last_index - 1] >= nums[last_index])
            --last_index;
        // cout << "first index: " << first_index << endl;
        // cout << "last index: " << last_index << endl;
        if (last_index == 0)
        {
            stable_sort(nums.begin(), nums.end());
            return;
        }
        int swap_index = -1;
        for (int i = last_index; i < nums.size(); i++)
        {
            if (nums[i] > nums[last_index - 1] && (swap_index == -1 || nums[i] < nums[swap_index]))
                swap_index = i;
        }
        swap(nums[last_index - 1], nums[swap_index]);
        stable_sort(nums.begin() + last_index, nums.end());
        return;
    }
};
// @lc code=end

