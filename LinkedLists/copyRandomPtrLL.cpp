/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//diff type of ll, has a random pointer that can point to legit any element in the LL. we need to copy this LL, that is, make new copy nodes with same values as before     

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //first we put the new nodes in between each real nodes. interleaving basically
        Node* iter = head;
        Node* front = head;
        if(head == NULL) 
        {
            return nullptr;
        }
        while(iter!=NULL)
        {
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        //then, we point the random nodes first
        iter = head;
        Node* nullNode = NULL;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        //now to fix the linked lists, we have to break the bonds between the copied nodes and real ones
        //we need a dummy, an iterator, a front and a temp to iterate through copied ll
        Node* dummy = new Node(0);
        Node* temp = dummy;
        dummy->next = head->next;
        iter = head;
        while(iter!=NULL)
        {
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            dummy = dummy->next;
            iter = iter->next;
        }

        return temp->next;
    }
};
