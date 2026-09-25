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
        if(head == NULL || head->next == NULL) return head;
        //initialise front, back, current
        ListNode* front = NULL;
        ListNode* curr = head;
        ListNode* back = NULL;

        while(curr != NULL){
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;

        }
        return back;
    }
};