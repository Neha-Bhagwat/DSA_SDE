//logic->slow and fast ptr intersect once,
//after that what we do is, we move the fast to the head and then fast and slow at the same pace till they intersect.
//that node is the cycles beginning. proof in notes

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        //for the edge case where there is a single node LL
        if(head == NULL || head->next == NULL) return NULL;
        //if slow and fast ptr ever coincide, then there is definitely a cycle
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while((slow!=fast) && fast!=NULL && fast->next != NULL)
        {
            //initially, till the nodes dont coincide
            slow = slow->next;
            //move slow by one and fast by 2
            fast = fast->next->next;
        }
        if(slow!=fast)
        {
            return NULL;
        }
        //now what we do is, move fast back to head
        fast = head;
        //then we move both at the same pace until they intersect
        while(fast!=slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;

    }
};
