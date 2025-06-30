class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //logic - 
        //first start pointers from beginning of head a, other from head b
        //after one reaches end, it goes to start of the other linked list
        ListNode *itA = headA;
        ListNode *itB = headB;
        while(itA != itB) 
        {
            itA = itA == NULL? headB : itA->next; //first use of this operator in a qn that i have seen
            itB = itB == NULL? headA : itB->next;
        }
        return itA;
    }
};

//here in the if case, do not do itB->next == null as the check, it doesnt work very well if you do that 
//TC->O(2m)
//SC->O(1)
