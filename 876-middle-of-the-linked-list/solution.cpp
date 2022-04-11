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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        while((ptr2!= NULL) && (ptr2->next != NULL))
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return ptr1;
    }
};

/*
    STRATEGY
    We create two pointers, initially pointing to head. The idea behind two pointers is to make one of them traverse the linked list one by one (line 26), and make the other one traverse the list by jumping two nodes at a time (line 27). By the time the faster one (ptr2) reaches NULL, or the next node after is NULL (line 24), ptr1 reaches the middle of the list. We return ptr1. 
    Space Complexity is O(1) because we do not allocate dynamically.
    Time Complexity is O(n) because we traverse the list.

*/
