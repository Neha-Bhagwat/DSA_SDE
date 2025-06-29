//here, we give the next node in the LL's value to the initial one.
//then, we navigate such that the current points to current->next->next.
//so, we are deleting the node after the one we are supposed to technically
//but the problem clearly states what it wants lol
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
