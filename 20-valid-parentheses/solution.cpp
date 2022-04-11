/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
     
        for (int i = 0; i<s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            
            else
            {
                if(stk.empty()) 
                    return false;
                
                if((s[i]==')' && stk.top()=='(') || (s[i]==']' && stk.top()=='[') || (s[i]=='}' && stk.top()=='{')) 
                    stk.pop();

                else
                    return false;
            }
        }
        
        if (stk.size() != 0)
            return false;
        else
            return true;
          
    }
};

/*
    STRATEGY
    We start checking the string with a for loop. If the bracket is a left bracket, we push it into the stack. If it is a right bracket, we check 2 things:
    1. If the stack is empty.
    2. If the top of the stack is a reversed version of the current bracket.
    If the first case is true, we return false since the string is invalid. For the second case, we check is the top one is the reversed bracket. If it is, we pop it out. If the string passes these cases, we return true.
    
    Time complexity is O(n) because we are traversing the string.
    Space complexity is O(n) because we are using a stack.
*/
