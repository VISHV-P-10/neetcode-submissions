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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if(head==NULL || head->next==NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int len =0;
        // have to find size of the ll
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }

        int back = len-n; 
        for(int i=0;i<back;i++){
            curr = curr->next;
        }
    ListNode* nodetodelete = curr->next;
    curr->next = nodetodelete->next;

    delete nodetodelete;
    return dummy->next;

        //return head;
    }
};
