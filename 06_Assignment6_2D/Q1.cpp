/**Question 1**
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

**Example 1:**
Input:s = "IDID"
Output:[0,4,1,3,2]
*/

// SOLUTION
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>v;
        int m=0,mx=s.size();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
            {
                v.push_back(m);
                m++;
            }
            else if(s[i]=='D')
            {
                v.push_back(mx);
                mx--;
            }
        }
        if(s[s.length()-1]=='D')
        {
            v.push_back(mx);
        }
        else
        {
            v.push_back(m);
        }
        return v;
    }
};