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
    /* RECURSION: for straight order

    int findCarry(ListNode* l1, ListNode* l2){
        if(l1 == nullptr || l2 == nullptr){
            //base case 
            return 0;
        }
        int carry = findCarry(l1->next, l2->next);
        int sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Find lengths of both lists
        int len1 = 0, len2 = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        while (temp1) { len1++; temp1 = temp1->next; }
        while (temp2) { len2++; temp2 = temp2->next; }

        //pad shorter list with 0s
        while(len1 < len2){
            ListNode* newNode = new ListNode(0);
            len1++;
            newNode->next = l1;
            l1 = newNode;
        }
        while(len2 < len1){
            ListNode* newNode = new ListNode(0);
            len2++;
            newNode->next = l2;
            l2 = newNode;
        }
        
        int carry = findCarry(l1,l2);
        
        if (carry == 0) {
            return l1;
        } 
        else {
            ListNode* newNode = new ListNode(carry);
            newNode->next = l1;
            return newNode;
        }

    } */

    //ITERATIVE: for reversed list 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
     int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }

};