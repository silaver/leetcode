/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        stack<int> stk;
        
        for (int i = 0; i < 32; i++)
        {
            int a = n % 2;
            stk.push(a);
            n = n / 2;
            
        }
        
        int reversed;
        
        for (int i = 0; i<32; i++)
        {
            long long power = pow(2, i);
            reversed += (power * stk.top());
            stk.pop();
                
        }
        
        return reversed;

    }
};

/*
    STRATEGY
    In order to get the number's digits, we use modulo and division operators. Since the number is in base 2, we use %2 and /2 to go between the digits of the number. 
    Then, to reverse the binary number we use pow. We add 2 to the power of i with every loop and the top of the stack. We pop the added digit. We return reversed.
    
    Time Complexity is O(n) because for every for loop its n+n = 2n = O(n)
    Space Complexity is O() because we used stacks.


*/
