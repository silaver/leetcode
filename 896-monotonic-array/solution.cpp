/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution{
public:
    bool isMonotonic(vector<int> &nums){
        
        int length = nums.size();
        
        int increase = 1;
        int decrease = 1;
        
        for(int i = 0; i < length - 1; i++)
        {
            if (nums[i] <= nums[i+1])
            {
                increase++;
            } 
            
            if (nums[i] >= nums[i+1])
            {
                decrease++;
            }
        }
        
        if((increase == length) || (decrease == length))
        {
            return true;
        }
        return false;
    }
};

/*
    STRATEGY
    In line 12, we declare a length variable to get the size of the vector. In lines 14&15, we create two variables named increase and decrease and we set them to 0. We use these variables to check if the number of increasing or decreasing elements are equal to the length of the vector.
    In line 17, we crate a for loop to iterate on the vector. In the first if statement (line 19), we check if the adjacent elements are increasing. If it is, we increment the variable increase. In the second if statement (line 24), we check if the adjacent elements are decreasing. If it is, we increment the variable decrease.
    Finally, we check if increase and length or decrease and length are equal. By using OR we check if one of them is true. If it is, we return true.
*/
