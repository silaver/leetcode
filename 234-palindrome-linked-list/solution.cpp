/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)
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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        
        ListNode* trav = head;
        
        while(trav != NULL)
        {
            stk.push(trav->val);
            trav = trav->next;
        }
        
        while(head)
        {
            if(stk.top() != head->val) 
                return false;
            
            stk.pop();
            head = head->next;
        }
        
        return true;
    }
};

/*
    STRATEGY
    Since there were many indices to work with and we need to check the reverse of the list, I decided to use stack.
    I created a trav variable to traverse the list and created a while loop to add the values of the nodes into the stack. Trav iterates the list until the end (line 24), then we add the value of the node into the stack (line 26), after that trav goes to the next node (line 27). 
    Then, since the top of the stack is actually the end of our linked list, we check if the top of the stack and the value of head is equal or not (line 32). If it is not, we return false. If it is, we pop and check the next node. If everything is the same, we return true. 
    
    Time Complexity is linear because we pop until the last element.
    Space Complexity is also linear because we store n elements in the stack.
*/
