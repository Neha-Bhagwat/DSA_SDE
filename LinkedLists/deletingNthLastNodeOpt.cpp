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
      //have a dummy node so we can return dummy->next and avoid the problem that arises because of the edgecase when n = length of array
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i = 0; i < n ; i++)
        {
          //fast goes ahead n times
            fast = fast->next;
        }
        while(fast->next!=NULL)
        {
          //move slow and fast until fast goes to the end
            slow = slow->next;
            fast = fast->next;
        }
        //now slow is where it should be to delete the next node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};
//Tc->O(n)
//SC->O(1)
