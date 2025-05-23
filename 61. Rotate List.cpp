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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;

        int length = 1;
        while(temp->next != NULL){
            temp = temp->next;
            length++;
        }

        k = k % length;

        temp = head;

        for(int i = 1; i < length-k; i++){
            temp = temp->next;
        }

        ListNode* rotateLast = temp;
        ListNode* last = temp;

        while(last->next != NULL) {
            last = last->next;
        }

        last->next = head;
        head = rotateLast->next;
        rotateLast->next = NULL;

        return head;

    }
};
