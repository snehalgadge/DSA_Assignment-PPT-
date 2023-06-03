/**Question 7**
Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

**Example 1:**
**Input:** s = "ab#c", t = "ad#c"
**Output:** true
*/

// SOLUTION
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string s1;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#' && !st.empty())
                    st.pop();
        
            else if(s[i]!='#')
                st.push(s[i]);
        }
        
        stack<char> stk;
        string s2;
        for(int i=0; i<t.size(); i++){
            
            if(t[i]=='#' && !stk.empty())
                    stk.pop();
            
            else if(t[i]!='#')
                stk.push(t[i]);
        }
        
        while(!st.empty()){
            s1.push_back(st.top());
            st.pop();
        }
        
        while(!stk.empty()){
            s2.push_back(stk.top());
            stk.pop();
        }
        
        return s1 == s2;
        
    }
};