
//logic::
//here, we add the two digits and if there is a carry, store it separately and give the answer using this logic
//sum = (addition+carry)%10
//carry = sum/10
//this goes on for every iteration
//the most imp catch is that when both the ll are over, there can still be a carry that causes an extra digit in the answer LL
//so look at the while loop and the way we use the conditions here
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode;
        ListNode* temp = dummy;
        int carry = 0;
        //logic:
        //add the leftmost digits onwards
        //we do this until one l1 goes to null
        while(l1!=NULL || l2!=NULL || carry != 0)
        {
            int sum = carry;
        //sum = addition%10+carry
        //carry = sum/10
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
        //inc l2
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            sum = sum%10;
        //increment temp 
        //inc l1;
            temp->next  = new ListNode(sum);
            temp = temp->next;
        }
        return dummy->next;
    }
};
