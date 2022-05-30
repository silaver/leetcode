class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxHeap;
        
        for (int i : nums)
            maxHeap.push(i);
        
        int a = maxHeap.top();
        maxHeap.pop();
        
        int b = maxHeap.top();
        
        return (a-1) * (b-1);
    }
};