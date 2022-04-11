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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr)
        {
            st.push(curr);
            curr = curr->next;
        }
        int len = st.size()/2;
        curr = head;
        
        while(len--)
        {
            ListNode* top = st.top();
            top->next = curr->next;
            curr->next = top;
            curr = top->next;
            st.pop();
        }
        curr->next = NULL;
    }
};
