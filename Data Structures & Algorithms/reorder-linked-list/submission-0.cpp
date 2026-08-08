// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode* front;
//     void solve(ListNode* back){
//         //i've no idea about the base case right now
//         // but we need to travers till the last in list for back
//         // base case if reached till end
//         if(back!=NULL) return ;
//         solve(back->next);
//         // we reached till last

//         // need to check if front and back crossed eeach other
//         if(front==NULL || front==back || front->next==NULL) return ;
//         // perfrom the operations
//         ListNode* nextfront = front->next;
//         front->next = back;
//         back->next= nextfront;

//         // update the front
//         front = nextfront;
//     }
//     void reorderList(ListNode* head) {
//         // again solve this hoe using recursion
//         // solve this as the swaping in pairs problem
//         // base case
//         // if(head==NULL || head->next==NULL) return;
//         // ListNode* first = head;
//         // ListNode* temp = head;
//         // while(temp->next!=NULL){
//         //     temp = temp->next;
//         // }
//         // ListNode* last = temp;
//         // ListNode* rem = reorderList(first->next);

//         // first->next = last;
//         // last->next = rem;

//         front = head;
//         solve(head);
//     }
// };

// class Solution {
// public:
//     ListNode* front;

//     void solve(ListNode* back) {

//         // Recursively go to the end
//         if (back == NULL) {
//             return;
//         }

//         solve(back->next);

//         // Stop when the front and back pointers meet/cross
//         if (front == NULL || front == back || front->next == back) {
//             return;
//         }

//         // Store the next front node
//         ListNode* nextFront = front->next;

//         // Insert back after front
//         front->next = back;
//         back->next = nextFront;

//         // Move front forward
//         front = nextFront;
//     }

//     void reorderList(ListNode* head) {
//         front = head;
//         solve(head);

//             if (front != NULL) {
//             front->next = NULL;
//         }
//     }
// };

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
    void reorderList(ListNode* head) {
        head = rec(head, head->next);
    }

private:
    ListNode* rec(ListNode* root, ListNode* cur) {
        if (cur == nullptr) {
            return root;
        }

        root = rec(root, cur->next);
        if (root == nullptr) {
            return nullptr;
        }

        ListNode* tmp = nullptr;
        if (root == cur || root->next == cur) {
            cur->next = nullptr;
        } else {
            tmp = root->next;
            root->next = cur;
            cur->next = tmp;
        }

        return tmp;
    }
};