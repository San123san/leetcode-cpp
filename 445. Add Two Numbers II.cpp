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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == NULL && l2 == NULL) return NULL;

        l1 = reverse(l1);
        l2 = reverse(l2);

        int carry = 0;
        ListNode* temp = NULL;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* res = NULL;

        while(curr1 != NULL || curr2 != NULL){
            int sum = carry;
            if(curr1){
                sum += curr1->val;
                curr1 = curr1->next;
            }

            if(curr2){
                sum += curr2->val;
                curr2 = curr2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            newNode->next = res;
            res = newNode;
        }

        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = res;
            res = newNode;
        }

        return res;
    }
};
