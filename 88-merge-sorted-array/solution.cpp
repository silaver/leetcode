/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(m+n)
    Space Complexity: O(1)

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = 0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
    }
};

/*
    STRATEGY
    First, in line 12 we create a for loop to iterate on nums2. In line 14, we merge nums1 and nums 2 together by adding the element of nums2 at the end of nums1. Then, in line 17 we use std::sort() to sort nums1. Because sorting algorithms like bubble sort and selection sort remove the duplicates, we use std::sort to keep them.
*/
