/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<ListNode*> node_ptr;
        ListNode* tmp_ptr = head;
        while (tmp_ptr != nullptr)
        {
            node_ptr.push_back(tmp_ptr);
            tmp_ptr = tmp_ptr->next;
        }
        if (node_ptr.size() == n)
            head = head->next;
        else
            node_ptr[node_ptr.size() - n - 1]->next = node_ptr[node_ptr.size() -n]->next;
        return head;
    }
};
// @lc code=end

