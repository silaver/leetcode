/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)

*/

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> stk;
        
        stk.push(s[0]);
        
        for(int i = 1; i < s.size(); i++) 
        {
            if(!stk.empty() && stk.top() == s[i]) 
                stk.pop();
            
            else 
                stk.push(s[i]);
        }
        
        string ans;
        
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
    STRATEGY
    We create a stack to check the indices. Starting with pushing the first element into the stack, we check if the stack is empty or the top of the stack is equal to the letter in the string. If the stack is not empty and the other case is true, we pop the element in the stack to remove the duplicate. If there are no duplicates, we keep pushing the letters into the stack. We store the final string in the ans variable. Because we used a stack, we reverse the string. We return ans.
    Time Complexity is O(n) because of the loops are O(n) each.
    Space Complexity is O(n) because we used stack.
*/
