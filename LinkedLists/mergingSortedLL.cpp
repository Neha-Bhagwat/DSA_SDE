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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* res = NULL;
        if(l1->val>l2->val) 
        {  
            swap(l1,l2);
        }
        res = l1;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* temp = l1;
            while(l1 !=NULL && l1->val <= l2->val)
            {
            //check if l1<l2
                temp = l1;
                l1 = l1->next;
            //if yes, temp becomes l1 and l1 becomes l1 next
            }
            //else
            //temp next goes to l2
                temp->next =l2;
            // swap l1 and l2
                swap(l1,l2);
            //make temp l1
                temp = l1;
    
        }
        return res;
    }
};
//here, we make connections in place, we do not make a new linked list. this makes life harder but this is the optimal solution
//tc->O(n+m)
//sc->O(1)

//learnings: write your logic down first
//swap only using std::swap. do not write your own swapping logic. it gives problems with null values
//use as less variables as possible to make your life easier
