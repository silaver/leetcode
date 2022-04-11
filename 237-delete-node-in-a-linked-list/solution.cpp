/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val; //store the next node's value into the inital node given
        ListNode* temp = node->next; //mark the next node to deallocate later
        node->next = node->next->next; //remove the last node
        
        delete temp; //deallocate temp
        
    }
};

/*
    STRATEGY
    Because we cannot reach head or the previous nodes, we store the next node's value into our initial node (line 19). 
    This "creates" two of the same nodes, so we create a temp variable to deallocate the repetitive node. We assign its value to the other node (line 20).
    Then, we remove the next node by node->next->next.
    We deallocate temp to avoid memory leak.
    
    Time complexity is O(1) because we do not traverse the linked list.
    Space complexity is O(1) because we do not allocate dynamically.
*/
