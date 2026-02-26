/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
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
    int removeDuplicates(vector<int>& nums) 
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
            {
                index += 1;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};
// @lc code=end