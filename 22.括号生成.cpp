/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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

void make_result(deque<char> st, int l_num, int r_num, int target, vector<string>& result);

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        deque<char> st;
        make_result(st, 0, 0, n, result);
        return result;
    }
};

void make_result(deque<char> st, int l_num, int r_num, int target, vector<string>& result)
{
    if (l_num == target)
    {
        string tmp_result = "";
        while (!st.empty())
        {
            tmp_result.push_back(st.front());
            st.pop_front();
        }
        for (int i = r_num; i < target; ++i)
            tmp_result.push_back(')');
        result.push_back(tmp_result);
        return;
    }
    st.push_back('(');
    make_result(st, l_num + 1, r_num, target, result);
    st.pop_back();
    if (l_num > r_num)
    {
        st.push_back(')');
        make_result(st, l_num, r_num + 1, target, result);
    }
    return;
}
// @lc code=end