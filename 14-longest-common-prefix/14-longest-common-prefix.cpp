/*
    SILA ER
    ID: 20201701041
    TC: O(n log n)m
    SC: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        if (n == 0)     //If the string is empty, return an empty string.
            return "";
        
        string ans  = ""; //Store the answer variable
        
        sort(begin(strs), end(strs)); //Sort the string
        string a = strs[0]; //First string in the array strs
        string b = strs[n-1]; //Last string in the array strs
        
        for(int i = 0; i < a.size(); i++){ 
            
            if (a[i] == b[i]) 
                ans = ans + a[i];
            else
                break;   
        }
        return ans;
    }
};

/*
    STRATEGY
    Using std::sort, we sort the array of strings. After that, we choose the first and last string in the array because they are the most different strings in the sorted array. We compare how many common characters there are from the start of a (i = 0) of these two strings.
    TC is O(n log n)m because we used a sorting algortihm. n logn is the complexity of the sorting algorithm, and we take m as the size of each string.
    SC is O(1) because we did not allocate anything dynamically.
*/