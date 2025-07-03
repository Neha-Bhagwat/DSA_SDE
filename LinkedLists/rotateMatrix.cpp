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

//

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {   
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            curr = curr->next;
            count++;
        }        

        if(head == NULL || k==0)
        {
            return head;
        }

        //rotate k%count times
        for(int i = 0; i < k%count; i++)
        {
            //rotation logic
            //take a dummy node, 
            ListNode* dummy = NULL; //need to somehow point second last to null
            curr = head;
            //take it to the second last node and 
            while(curr->next->next!=NULL)
            {
                curr = curr->next;
            }
            ListNode* lastNode = curr->next;
            //last node and 
            //last to head
            lastNode->next = head;
            //point second last to null and 
            curr->next = dummy;
            head = lastNode;
        }
        return head;
    }
};
