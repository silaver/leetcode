/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void ans(vector<char>&s, int i, int n)
    {
        if(i > n/2) 
            return;
        
        swap(s[i], s[n-i]);
        
        ans(s, i+1, n);
    }
    
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        return ans(s, 0, n-1);
           
    }
};
/*
    STRATEGY
    We create a variable n with the value of s.size() (line 22). In the ans function, we create a variable i initially equal to 0. We check if i is greater than half of n (if it is beyond the middle of the string). If it is not, we recursively swap the i-th and the (n-i)th element until i is greater than n/2. We increment i with every swap as well.
    Space complexity is constant because we pass by reference.
*/