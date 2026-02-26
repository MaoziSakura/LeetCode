/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* one = nullptr;
        ListNode* two = nullptr;
        ListNode* result = new ListNode();
        ListNode* last = result;
        result->next = head;

        while (head != nullptr)
        {
            one = head;
            two = head->next;
            if (two == nullptr)
                break;
            head = two->next;
            two->next = one;
            one->next = head;
            last->next = two;
            last = one;
        }

        return result->next;
        
    }
};
// @lc code=end

