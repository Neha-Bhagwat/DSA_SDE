//reversing half of ll
//we make a new reversing function, which isnt strictly necessary, we could do it in a while loop too
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        //find midpoint
        ListNode* slow = head;
        ListNode* fast = head;

        if(head== NULL && head->next == NULL) return true;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the rest of the ll using a new function
        slow = ReverseLL(slow->next); //here, slow points to the head of the newly reversed ll

        // then check the original node with the dummy node till slow goes to null
        fast = head;
        while(slow != NULL)
        {
            // cout<<slow->val<<" "<<fast->val<<endl;
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }


    ListNode* ReverseLL(ListNode* head)
    {
        ListNode* dummy = NULL;
        while(head!=NULL)
        {
            ListNode* nex = head->next;
            head->next = dummy;
            dummy = head;
            head = nex;
        }

        return dummy;
    }

//TC-> O(n)+O(n/2)+O(n/2) = O(2n)
//SC-> O(1)
