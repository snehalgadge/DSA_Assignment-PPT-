/**Question 2**
Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is **valid***.
The following rules define a **valid** string:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

**Example 1:**
**Input:** s = "()"
**Output:**true
*/

// SOLUTION
class Solution {
public:
    bool checkValidString(string s) {         
        
        stack<char> open,star;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open.push(i);
            if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else{
                    if(!star.empty()) star.pop();
                    else{
                        return false;
                    }
                }
            }
        }
        while(!open.empty() and !star.empty() and open.top()<star.top()){
            open.pop();
            star.pop();
        }

        return (open.empty()) ? true : false;
    }
};
