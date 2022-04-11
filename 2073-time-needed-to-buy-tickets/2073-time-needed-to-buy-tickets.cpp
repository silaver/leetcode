/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        
        for(int i = 0; i != tickets.size(); i++) 
            q.push(i);
        
        int time = 0;
        
        while(true)
        {
            time++;
            int p = q.front(); 
            q.pop();
            
            if(tickets[p]) 
                tickets[p]--;
            
            if(tickets[p]) 
                q.push(p);    
            
            if(p == k && tickets[p] == 0) 
                return time;
        }
    
        return 0;
    }
};

/*
    STRATEGY
    Firstly, we push all of the elements of the array into a queue. We set the time to 0. With a while loop, we keep selling tickets k times. We set the variable p to the front of the queue. If p has not yet reached zero, we decrement it (equal to selling one ticket). Then, we push the decremented value into the queue again. We increment the time. 
    Time Complexity is O(n) because we traversed the vector and used a while loop.
    Space Complexity is O(n) because we used queues.

*/