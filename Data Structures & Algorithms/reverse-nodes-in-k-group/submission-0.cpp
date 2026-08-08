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
    ListNode* reverseKGroup(ListNode* head, int k) {
          ListNode dummy(0,head);
        //dummy->next = head;
      //  ListNode* prev = dummy->next;
      ListNode* prev = &dummy;
        // find the end node
        
        while(1){
            ListNode* end = prev;
            for(int i=0;i<k && end;i++){
                // start from the dummy itself
                end = end->next;
            }
            // loop breaking 
            if(!end) break;
            ListNode* curr = prev->next;
            ListNode* nxt = curr->next;
            ListNode* stop = end->next;

            while(nxt!=stop){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
        }
        return dummy.next;
        
    }
};
