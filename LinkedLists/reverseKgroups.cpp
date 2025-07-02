//for logic, youll need to draw everything, remember that at the beginning we need to keep a gap of one node between prev and prev->next as well as curr and curr->next
//also, check the logic of what happens to prev, curr and next between iterations of k-1 switching
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        if(head == NULL || k == 1) return head; //no changes needed

        //for now, the prev and curr will point to dummy
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head; 

        while(curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        ListNode* nex = dummy;
        curr = dummy;
        while(count>=k)
        {
            curr = prev->next;
            nex = curr->next;
            for(int i = 1; i<k;i++)
            {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            count -= k;
            prev = curr;
        }
        return dummy->next;
    }
};
