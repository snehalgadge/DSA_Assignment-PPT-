/*<aside>
💡 **Question 7**

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

</aside>*/

// SOLUTION
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push({val,val});

        }
        else{
            if(st.top().second < val){
                st.push({val,st.top().second});
            }
            else{
                st.push({val,val});
            }
        }
    }
    
    void pop() {
        if(st.size()){
            st.pop();
        }
    }
    
    int top() {
        if(st.size()){
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() {
        return st.top().second;
    }
};
