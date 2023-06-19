/*<aside>
💡 **Question 6**

Given string **S** representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like ***, /, + and -**.

</aside>*/

// SOLUTION
class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(char x: S)
        {
            if((x=='*' || x=='/' ||x=='+' ||x=='-') )
            {
                    int a= st.top(); st.pop(); 
                    int b= st.top();  st.pop();
                
                switch(x)
                {
                   case '*' : st.push(a*b); break;
                    case '/' : st.push(b/a); break;
                    case '+' : st.push(a+b); break;
                    case '-' : st.push(b-a); break;
                }
            }
            
            else {   
                
                if(x >= '0' and x<='9')
                {
                    st.push((x - '0')); 
                }
            }
        }
        
        return st.top();
    }
};