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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }

        while (a != NULL) {
            curr->next = a;
            a = a->next;
            curr = curr->next;
        }

        while (b != NULL) {
            curr->next = b;
            b = b->next;
            curr = curr->next;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;

        for(int i = 0; i < lists.size(); i++){
            res = merge(res, lists[i]);
        }
        return res;
    }
};
