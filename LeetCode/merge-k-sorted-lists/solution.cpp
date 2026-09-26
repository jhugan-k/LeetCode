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

    // use heap to get minimum list head values
    // use custom comparator.
    // don't push empty list.
    
    struct compare{
        bool operator()(ListNode* &a, ListNode* &b){
            return a->val > b->val; //ascending order
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto list : lists) {
            if(list) pq.push(list);
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(!pq.empty()){
            auto head = pq.top();
            pq.pop();
            // connect to dummy
            tail->next = head;
            tail = tail->next;
            if(tail->next) pq.push(tail->next); // push remaining part of head, if exists.

        }
        return dummy->next;

    }
};