//using fast and slow ptr methods
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        //for the edge case where there is a single node LL
        if(head == NULL || head->next == NULL) return false;
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
        return slow==fast;
    }
};
//TC->O(n)
//SC->O(1)
