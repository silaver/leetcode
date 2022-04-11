/*
    SILA ER
    ID: 20201701041
    Time Complexity: O()
    Space Complexity: O()
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> newRow(rowIndex+1, 1);
        
        if (rowIndex > 1) 
        {
            vector<int> preRow = getRow(rowIndex-1);
            
            for (int i = 1; i < rowIndex; i++) 
                newRow[i] = preRow[i-1] + preRow[i];
        }
        return newRow;
    }
};

/*
    STRATEGY
    
           
*/