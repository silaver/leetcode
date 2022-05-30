class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> elementToFreqMap; 
        //key=element of nums array, value=freq of that element in the nums array
        
        for(int num: nums){
            elementToFreqMap[num]++;
        }
        
        for(auto it: elementToFreqMap){
            if(it.second == 1) //if the frequency is equal to 1
                return it.first; //return the key value
        }
        
        return -1;
    }
};