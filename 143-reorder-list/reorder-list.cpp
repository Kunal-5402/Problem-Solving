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
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL or head->next->next == NULL){
            return;
        }

        stack<ListNode*> s;
        ListNode * temp = head;
        int count = 0;

        while(temp){
            s.push(temp);
            count++;
            temp = temp->next;
        }

        temp = head;

        for(int i=0;i<count/2;i++){

            ListNode * top = s.top();
            s.pop();

            top->next = temp->next;
            temp->next = top;
            temp = temp->next->next;
        }
        temp->next = NULL;
    }
};