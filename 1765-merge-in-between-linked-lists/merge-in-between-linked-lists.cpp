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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;

        ListNode * temp = list1;

        ListNode * start = NULL;
        ListNode * end = NULL;

        while(temp){
            if(i == a-1)
                start = temp;
            if(i == b+1)
                end = temp;
            temp = temp->next;
            i++;
        }
        start->next = list2;
        while(list2->next != NULL){
            list2 = list2->next;
        }
        list2->next = end;
        // cout<<start->val<<endl;
        // cout<<end->val<<endl;
        return list1;
    }
};