/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) 
    {
        int result = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else
            {
                if (st.size() != 0)
                {
                    st.pop();
                    result += 2;
                }
            }
        }
        return result;
    }
};
// @lc code=end

