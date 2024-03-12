/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

1,3,2,-3,-2,5,5,-5,1

1,-,-,-,-,5,-,-,1

 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        vector<int> v;
        ListNode* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        unordered_set<int> ans;

        for (int i = 0; i < v.size(); i++) {
            int sum = 0;

            for (int j = i; j < v.size(); j++) {
                sum += v[j];

                if (sum == 0) {
                    for (int k = i; k <= j; k++)
                        ans.insert(k);
                    i = j + 1;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
            if (ans.count(i) == 0)
                res.push_back(v[i]);
        }
        if (res.size() == 0)
            return nullptr;

        if (res[0] == 0)
            return nullptr;

        ListNode* node = new ListNode();
        head = node;

        for (int i = 0; i < res.size(); i++) {
            node->val = res[i];
            if (i != res.size() - 1) {
                node->next = new ListNode();
                node = node->next;
            }
        }
        for (auto it : res) {
            cout << it << " ";
        }
        return head;
    }
};