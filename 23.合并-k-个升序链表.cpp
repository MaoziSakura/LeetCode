/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int mins = INT_MAX;
        int min_index = -1;
        ListNode* min_ptr = nullptr;
        ListNode* head = new ListNode();
        ListNode* tmp_ptr = head;
        bool flag = true;
        while (true)
        {
            flag = true;
            mins = INT_MAX;
            min_ptr = nullptr;
            for (int i = 0; i < lists.size(); ++i) 
            {
                if (lists[i] == nullptr)
                    continue;
                flag = false;
                if (mins > lists[i]->val)
                {
                    mins = lists[i]->val;
                    min_ptr = lists[i];
                    min_index = i;
                }
            }
            if (flag)
                break;
            tmp_ptr->next = min_ptr;
            tmp_ptr = min_ptr;
            lists[min_index] = lists[min_index]->next;
        }
        return head->next;
    }
};
// @lc code=end

