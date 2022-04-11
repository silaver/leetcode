/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr = head;      //curr variable to point at head
        ListNode* prev = nullptr;   //prev is NULL
        
        while(curr)   // curr !=0
        {
            ListNode* Next = curr->next;    // 
            curr->next = prev;
            prev = curr;
            curr = Next;    
        }
        
        return prev;
    }
};

/*
    STRATEGY
    We point the next pointer to the next node of our current node. We update cur -> next = prev, this reverses the list. Then, we update previous and current to their next nodes.
    Time Complexity is O(n) because of traversing the list.
    Space Complexity is O(1) because we did not use dynamic allocation.

*/
