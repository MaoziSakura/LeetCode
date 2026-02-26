/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
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

using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int l, r;
        long long int sum = 0;
        long long int tmp_sum = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> tmp_result;
        set<vector<int>> flag_set;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                l = j + 1;
                r = nums.size() - 1;
                sum = nums[i] + nums[j];
                while (l < r)
                {
                    tmp_sum = sum + nums[l] + nums[r];
                    if (tmp_sum < target)
                        ++l;
                    else if (tmp_sum > target)
                        --r;
                    else
                    {
                        // tmp_result.clear();
                        tmp_result = {nums[i], nums[j], nums[l], nums[r]};
                        if (flag_set.find(tmp_result) == flag_set.end())
                        {
                            result.push_back(tmp_result);
                            flag_set.insert(tmp_result);
                        }
                        ++l;
                        --r;
                    }
                }

            }
        }
        return result;
    }
};
// @lc code=end

