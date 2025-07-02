//time limit exceeded
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //approach 1, figure out the length of the list
        //then for first element, iterate to next n-1 times and compare value with first node
        //then for second element, iterate n-2 times
        //do this with pointers while front!=back, dont need to write the equal to condition
        //lets try to code my method
        int length = 0;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            curr = curr->next;
            length++;
        }
        ListNode* front = head;
        ListNode* back = front->next;
        int checkNum = 1;
        while(front!=back && front != NULL && back!= NULL)
        {
            back = head;
            for(int i = 1; i <= length-checkNum; i++)
            {
                back = back->next;
                //cout<<back<<endl;
            }
            if(front->val != back->val)
            {
                return false;
            }
            front = front->next;
            checkNum++;
        }
        return true;
    }
};
