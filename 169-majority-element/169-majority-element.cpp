class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> um;
        
        for (auto x: arr){
            um[x]++;
            
            if (um[x] > arr.size()/2)
                return x;   
        }
        return 0;
    }
};
