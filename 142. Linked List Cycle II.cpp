/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        if(fast == NULL || fast->next == NULL) return nullptr;

        int count = 0;

        if(slow == head && fast == head){
            return slow;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            count++; 
        }
        return slow;
    }
};
