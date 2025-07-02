//GOOD SUM, PRACTICE AGAIN

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution 
{
public:
//this function will keep calling itself till the last 2 LLs are the ones it is merging.
//it will merge those 2 lls
//then it will return the head of that merged ll
//after that the operation will be conducted on the newly merged ll and the third last LL
//this will keep happening until the, where only one LL is left
    ListNode* flattenLinkedList(ListNode* &head) 
    {
        //recursion in this one. flatten keeps calling merge to LLs
        //base case
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //when you flatten the next node, it should go to that node only
        head->next = flattenLinkedList(head->next);

        //merge and keep flattening and merging
        head = mergeLL(head, head->next);        

        return head;
    }

//this function gives the merging logic of two LLs. it uses merge sort algorithm where we check which is the smaller number of two
//then we link the old node to the smaller one
//we iterate ahead
//finally, we return the first node using res->child as the logic behind it.
    ListNode* mergeLL(ListNode* a, ListNode* b)
    {
        //make temp and res
        ListNode* temp = new ListNode();
        ListNode* res = temp;
        
        //now the loop starts
        while(a != NULL && b != NULL)
        {
            if(a->val>b->val)
            {
                temp->child = b;
                b = b->child;
            }
            else
            {
                temp->child = a;
                a = a->child;
            }
            temp = temp->child;
        }
        if(a!=NULL) temp->child = a;
        else temp->child = b;
        return res->child;
    }
};


