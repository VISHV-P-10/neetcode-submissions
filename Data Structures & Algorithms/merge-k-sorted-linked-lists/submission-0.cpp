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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // make a min heap
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>p;

        ListNode* root = new ListNode(-1);
        ListNode* tail = root;

        //push the first elememts of all the linked list
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
            p.push({lists[i]->val,lists[i]});
            }
        }
        while(!p.empty()){
            auto it = p.top();
            p.pop();
            if(it.second->next){
                p.push({it.second->next->val,it.second->next});
            }

            tail->next = it.second;
            tail = tail->next;
        }
        return root->next;
    }
};
