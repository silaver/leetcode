class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0; i<score.size(); i++)
            maxHeap.push(pair<int,int>(score[i],i));
        
        vector<string> ans;
        for(int i=0; i<score.size(); i++)
            ans.push_back("");
        
        int i=0;
        while(!maxHeap.empty())
        {
            if (i==0)
                ans[(maxHeap.top()).second] = "Gold Medal";    
            else if(i==1)
                ans[(maxHeap.top()).second] = "Silver Medal"; 
            else if(i==2)
                ans[(maxHeap.top()).second] = "Bronze Medal"; 
            else
                ans[(maxHeap.top()).second] = to_string(i+1); 
            maxHeap.pop();
            i++;
        }
        return ans;
    }
};