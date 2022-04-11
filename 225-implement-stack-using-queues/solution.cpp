/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
class MyStack {
public:
    
    //create two queues
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        while(q1.size()){       //transfer everything to q2
            q2.push(q1.front()); 
            q1.pop();
        }
        
        q1.push(x);     //push the desired element
        
        while(q2.size()){       //push everything back to q1
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int top = q1.front(); 
        q1.pop();       //remove the top element
        return top;     // return that element
    }
    
    int top() {
        return q1.front(); //return front
    }
    
    bool empty() {
        return q1.empty() && q2.empty(); //return whether the stack is empty or not
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
    STRATEGY
    --Push--
    Normally, with a queue, if you push a element this happens:
    a b c d e   push(x)
    a b c d e x
    
    But with stacks we want to achieve this:
    x a b c d e
    
    To do this, we create two queues. First, we put everything in q1 to q2. We add the desired element into the front of q1. Then, we return everything from q2 to q1.
    Time Complexity is O(n)
    
    --Pop--
    We set top equal to the front of the queue. Pop that element, and return it.
    Time Complexity is O(1)
    
    --Top--
    Since we are not adding or removing anything, .front() does the same thing here.
    Time Complexity is O(1)
    
    --Empty--
    We check if q1 and q2 is empty with AND operator.
    Time Complexity is O(1)
    
    -------------------------------
    Space Complexity is O(n) overall because of using queues.

*/
