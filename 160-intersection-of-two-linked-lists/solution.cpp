/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *L1, ListNode *L2) 
    {
        std::stack<ListNode*> st1;
        std::stack<ListNode*> st2;
        
        while (L1)
        {
            st1.push(L1);
            L1 = L1->next;
        }
        
        while (L2)
        {
            st2.push(L2);
            L2 = L2->next;
        }
        
        ListNode* res = nullptr;
        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() != st2.top())
            {
                break;
            }
            
            res = st1.top();
            
            st1.pop();
            st2.pop();
        }
        return res;
    }
};
