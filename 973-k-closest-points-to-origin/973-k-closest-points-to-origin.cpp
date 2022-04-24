class Solution
{
public: 
    struct Point    // struct defining a point
    {
        vector<int> p;      // coordinates x and y are stored as a vector (only two elements)
        double d;           // distance to the origin (0,0)
 
     
    Point(int x, int y, double d)      // Constructor
    {
        this->p = {x, y};
        this->d = d;
    }
 };
    
 // Function to compare two points in terms of their distance to the origin
 // Time Complexity: O(1)
    struct ComparePoints
    {
        bool operator()(Point const &p1, Point const &p2) const
    {
    return p1.d < p2.d;
    }
 };
    
 /*
 Given a set of points (x,y), return the k closest points to the origin (0,0)
 PARAM vector<vector<int> > &, array of points
 PARAM int, number of points to be included in the solution
 Time Complexity: O(n log k), explanation is at the end of the function
 Space Complexity: O(k), size of the heap
 */
    
    vector<vector<int> > kClosest(vector<vector<int> > &points, int k)
    {
        priority_queue<Point, vector<Point>, ComparePoints> maxheap;
        // max heap to store the k closest points to the origin
        vector<vector<int> > ans; // array containing the k closest points to the origin
        // check all the points in the array of points, loops n times
        // add them in the heap but make sure that the size of the heap doesn’t exceed k
        // as we check points, if their distance to the origin is smaller than the maximum
        // in the heap, which is at the top of it, then poll the maximum and add the new point
    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i][0]; // x coordinate of i-th point
        int y = points[i][1]; // y coordinate of i-th point
        double dist = sqrt(x * x + y * y); // distance from the origin is given by this forumla
        
        Point p(x, y, dist); // object point to be inserted in the max heap
        // if there is room in the heap, then add the new point
        
        if (maxheap.size() < k)
            maxheap.push(p); // insert in heap, O(log k)
        
        // otherwise, only add it if the new point has a shorter distance than
        // the maximum of the minimum distances found so far
        else if (dist < maxheap.top().d) // peek from heap, O(1)
        {
            maxheap.push(p); // insert in heap, O(log k)
            maxheap.pop(); // poll from heap, O(log k)
        }
        // worst time for a single loop is O(log k + log k) = O(2 log k) = O(log k)
    }
        
    // at this point, the heap only contains the k closest elements to the origin
    // add them into an array
     while (!maxheap.empty()) // loops k times
    {
        Point p = maxheap.top(); // peek from heap, O(1)
        ans.push_back(p.p); // insert in vector, O(1) on average
        maxheap.pop(); // poll from heap, O(log k)
         // worst time for a single loop is O(log k)
         // inserting elements in vector might run in O(k) time if the vector is full
         // and it needs to be resized; however, we don't know when that will happen
         // so we can assume that the internal capacity of the vector 'c' is much larger than 'k'
         // c >> k
         // therefore we can ignore this
    }
         // this function will run in:
         // O(n log k) for the first for loop
         // O(k log k) for the while loop at the end
         // It should be O(n log k + k log k), but we know that n >= k, so
         // the time complexity will be O(n log k)

    return ans; // return the answer
    }
};