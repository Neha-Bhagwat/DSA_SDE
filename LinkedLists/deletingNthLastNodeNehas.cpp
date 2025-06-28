//logic->iterate once to find the length
//take into account edge cases (deleting head)
//use the logic of getting one element behind the one to be deleted
//do majja
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        //move the pointer from the head n-1 times.
        int length = 1;
        while(current->next!=NULL)
        {
            current = current->next;
            length++;
        }
        //cout<<length;
        if(n == length)
        {
            //special case when node to be deleted is head
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        current = head;
        for(int i = 0; i < length-n-1; i++)
        {
            current = current->next;
        }
        //delete the node after curr
        if(current->next->next!=NULL)
        {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        }
        else
        {
            ListNode* temp = current->next;
            current->next = NULL;
            delete temp;
        }
        //then, say current->next = current->next->next;
        return head;
    }
};
//TC->O(2n), SC->O(1)
