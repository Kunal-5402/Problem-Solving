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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        // ListNode * sentinel=NULL;
        // ListNode * next=head->next;
        // do{
        //     head->next=sentinel;
        //     sentinel=head;
        //     head=next;
        //     if(next!=NULL) next=next->next;
        // }while(head!=NULL);
        // return sentinel;
        vector<int> v;
        ListNode *temp=head,*ptr=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        reverse(v.begin(),v.end());
        for(auto it:v){
            ptr->val=it;
            ptr=ptr->next;
        }
        return head;
    }
};