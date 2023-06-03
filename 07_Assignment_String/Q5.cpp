/**Question 5**
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

**Example 1:**
**Input:** s = "abcdefg", k = 2
**Output:**"bacdfeg
*/

// SOLUTION
class Solution {
public:

    string reverseStr(string s, int k) {
        
        int i=0, t=0;
        while(i<s.size()){
            int start=i,end=i+k-1;
            if(i+k>=s.size())end=s.size()-i-1;
            if(s.size()-i<=k)end=s.size()-1;
            while(start<end){
                swap(s[start],s[end]);
                start++;end--;
            }
            i+=2*k;
        }
        return s;
    }
};