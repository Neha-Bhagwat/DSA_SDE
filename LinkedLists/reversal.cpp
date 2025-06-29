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

//logic:in place, change the direction of the links of all the elements
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        //use the head as the current node and keep traversing
        while(head!=NULL)
        {
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
            //head-> next = dummy; will happen in the next iteration
        }
            //return dummy node
        return dummy;
    }
};

//tc->O(n), sc->O(1)
