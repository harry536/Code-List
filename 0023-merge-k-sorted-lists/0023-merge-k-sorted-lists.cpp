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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    // If l1 is NULL, return l2
    if(l1 == NULL)
    {
        return l2;
    }
    
    // If l2 is NULL, return l1
    if(l2 == NULL)
    {
        return l1;
    } 
    
    // If the value of the first node of l1 is less than or equal to the value of the first node of l2,
    // recursively merge the remaining nodes of l1 and all of l2 after the first node.
    if(l1 -> val <= l2 -> val)
    {
        l1 -> next = mergeTwoLists(l1 -> next, l2);
        return l1;
    }
    // If the value of the first node of l2 is less than the value of the first node of l1,
    // recursively merge the remaining nodes of l2 and all of l1 after the first node.
    else
    {
        l2 -> next = mergeTwoLists(l1, l2 -> next);
        return l2;            
    }
}

// This function takes a vector of linked lists and merges all the linked lists in it.
ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    // If the input vector is empty, return NULL
    if(lists.size() == 0)   
    {
        return NULL;
    }

    // While there are more than one linked lists in the input vector, merge the last two lists,
    // remove them from the vector, and add the merged list to the end of the vector.
    while(lists.size() > 1){
        ListNode* l1 = lists.back();
        lists.pop_back();

        ListNode* l2 = lists.back();
        lists.pop_back();

        lists.push_back(mergeTwoLists(l1, l2));
    }

    // Return the head of the only linked list left in the input vector
    return lists[0];
} 
};