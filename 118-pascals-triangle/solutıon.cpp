class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> a;
		
		for(int i = 0; i < numRows; i++) 
        {
			vector<int> hold;
            
			for(int j = 0; j <= i; j++) 
            {
				hold.push_back(0); 
			}
			a.push_back(hold);
		}

		a[0][0] = 1;

		for(int i = 1; i < numRows; i++) 
        {
			a[i][0] = 1;
			a[i][i] = 1;

			for(int j = 1; j < i; j++) 
            {
				a[i][j] = a[i -1][j -1] + a[i -1][j];
			}
		}
		return a;
        
        
    }
};
