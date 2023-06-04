/**Question 5**
We are given a string S, we need to find count of all contiguous substrings starting and ending with same character.
*/

// SOLUTION

// C++ program to count all substrings with same
// first and last characters.
#include <bits/stdc++.h>
using namespace std;
 
// Returns true if first and last characters
// of s are same.
int checkEquality(string s)
{
    return (s[0] == s[s.size() - 1]);
}
 
int countSubstringWithEqualEnds(string s)
{
    int result = 0;
    int n = s.length();
 
    for (int i = 0; i < n; i++)
       for (int len = 1; len <= n-i; len++)
          if (checkEquality(s.substr(i, len)))
            result++;
 
    return result;
}