//logic- using hashing (unordered set) to check if there has been the same element present before in the ll
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *current = head;
        unordered_set<ListNode*> ht;
        while(current!=NULL)
        {
            //check if each element is present in hashtable
            if(ht.find(current)!= ht.end())
            {
                //if yes, return true
                return true;
            }
            //else, add to hashmap
            //go to next
            ht.insert(current);
            current = current->next;
        }
        return false;
    }
};
//tc->O(n)
//sc->O(n) . so interviewer wont be happy
