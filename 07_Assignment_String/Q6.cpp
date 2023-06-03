/**Question 6**
Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.
A **shift** on s consists of moving the leftmost character of s to the rightmost position.
- For example, if s = "abcde", then it will be "bcdea" after one shift.

**Example 1:**
**Input:** s = "abcde", goal = "cdeab"
**Output:**true
*/

// SOLUTION
class Solution {
public:
    bool rotateString(string s, string goal) {
        int l1=s.length();
        int i=0;
        bool ans=false;
        char temp=' ';
        if(s==goal)
        return true;

        for(i=1;i<l1;i++)
        {
            temp=s[0];
            s=s.substr(1,l1)+temp;
            if(s==goal)
            {
            ans=true;
            break;
            }
        }
        return ans;
    }
};