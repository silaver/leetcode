/*
    SILA ER
    ID: 20201701041
    TC: O(n)
    SC: O(1)

*/

class Solution {
    public :
    void reverse(vector<int>& nums, int i, int j){  // reversing the array values
        int left = i; 
        int right = j;
        
        while(left < right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            left++;
            right--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); //use modulo to get how many times should we reverse
        
        reverse(nums, 0, nums.size() - k - 1);          //reverse the first array
        reverse(nums, nums.size() - k, nums.size() - 1);//reverse the second array
        reverse(nums, 0, nums.size() - 1);              //reverse whole array
    }
};
/*
    STRATEGY
    In order to rotate an array, we need to take k values from the back and put in the front of the array. We can imagine the array as 2 parts. First part is until the last kth elements, and the second part is the last k elements which we have to rotate.
    To rotate this array k times we need to reverse the first part of the array. Then we reverse the second part of the array. Finally, we reverse the whole array. K can be a large integer to reverse that many times, so we modulo of "k" with length of array.
    TC is O(n) because we are using reverse().
    SC is O(1) because we did not allocate anything dynamically.

*/