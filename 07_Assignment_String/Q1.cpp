/**Question 1**
Given two strings s and t, *determine if they are isomorphic*.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**
**Input:** s = "egg", t = "add"
**Output:** true
*/

// SOLUTION
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,int>m;
      unordered_set<char>q;
      for(int i=0;i<s.length();i++)
      {
          if(m.find(s[i])==m.end())
          {
              if(q.count(t[i]))
                  return false;
              m[s[i]]=t[i];
              q.insert(t[i]);
          }
          else
              if(m[s[i]]!=t[i])
                  return false;
      }
    return true;
    }
};