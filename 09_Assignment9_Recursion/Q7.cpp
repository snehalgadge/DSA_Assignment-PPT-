/**Question 7**
Given a string S, the task is to write a program to print all permutations of a given string.

**Example 1:**
***Input:**S = “ABC”*
***Output:**“ABC”, “ACB”, “BAC”, “BCA”, “CBA”, “CAB”*
*/

// SOLUTION

    bool checkInclusionRecursive(string s1, string s2, int start, vector<int>& count1,vector<int>& count2) {
        if (start > s2.length() - s1.length())
            return false;

        if (isPermutation(count1, count2))
            return true;

        count2[s2[start] - 'a']--;
        if (start + s1.length() < s2.length())
            count2[s2[start + s1.length()] - 'a']++;

        return checkInclusionRecursive(s1, s2, start + 1, count1, count2);
    }