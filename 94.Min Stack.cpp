#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
    // Write your code here.
    stack<int> st;
    int mine;
    public:
        
        // Constructor
        minStack() 
        { 
            // Write your code here.
            mine = -1;
        }
        
        // Function to add another element equal to num at the top of stack.
        void push(int num)
        {
            // Write your code here.
            if(mine==-1){
                mine = num;
                st.push(num);
                return;
            }
            if(num<mine){
                int modified_value = 2*num-mine;
                st.push(modified_value);
                mine = num;
            }
            else    st.push(num);
        }
        
        // Function to remove the top element of the stack.
        int pop()
        {
            // Write your code here.
            if(mine==-1)    return -1;
            int tope = st.top();
            st.pop();
            if(st.empty()){
                mine=-1;
                return tope;
            }
            if(tope<mine){
                int value = mine;
                mine = 2*value-tope;
                return value;
            }
            else return tope;
        }
        
        // Function to return the top element of stack if it is present. Otherwise return -1.
        int top()
        {
            // Write your code here.
            if(mine==-1)    return -1;
            int tope = st.top();
            if(tope<mine)   return mine;
            return tope;
        }
        
        // Function to return minimum element of stack if it is present. Otherwise return -1.
        int getMin()
        {
            // Write your code here.
            return mine;
        }
};