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

//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL)
		return head;
        
        ListNode* curr = head;
	    
        while(curr->next != NULL)
        {
            if(curr->val == curr->next->val)
            {
                curr->val = curr->next->val; //store the next node's value into the inital node given
                ListNode* temp = curr->next; //mark the next node to deallocate later
                curr->next = curr->next->next; //remove the last node
        
                delete temp; //deallocate temp
            }
            
            else
                curr = curr->next;    
        }
        return head;
    }
};
