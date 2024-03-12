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
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode * node = new ListNode(0,head);
        ListNode * temp = node;
        int prefix = 0;
        unordered_map<int,ListNode*> m;

        while(temp){
            prefix += temp->val;
            m[prefix] = temp;
            temp = temp->next;
        }

        prefix = 0;
        temp = node;

        while(temp){
            prefix += temp->val;
            temp->next = m[prefix]->next;
            temp = temp->next;
        }
        
        return node->next;
    }
};