/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
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

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if ((int)nums.size() == 1)
            return 0;
        
        int maxs = -1, step = 0, jump = -1, next_start = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + jump >= (int)nums.size())
                break;
            step++;
            if (next_start == -1)
            {
                next_start = i;
                jump = nums[i];
                continue;
            }
            maxs = -1;
            for (int j = 0; j < jump; j++)
            {
            int k = i + j;
                if (k > (int)nums.size())
                    break;
                if (k + nums[k] >= maxs)
                {
                    maxs = k + nums[k];
                    next_start = k;
                }
                if (jump >= nums.size())
                    break;
            }
            jump = nums[next_start];
            i = next_start;
        }
        return step;
    }
};

// @lc code=end

// int main()
// {
//     vector<int> a = {5, 2, 2, 1, 1, 1, 100, 1, 1, 1, 1, 1, 1};
//     Solution solution;
//     solution.jump(a);
// }

//
//  [5,2,2,1,1,1,100,1,1,1,1 ,1 ,1 ,1]
//   0,1,2,3,4,5,6  ,7,8,9,10,11,12,13
//    ,3,4,4,5,6,106,8
//
//