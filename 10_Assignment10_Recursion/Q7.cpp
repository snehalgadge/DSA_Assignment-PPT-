/**Question 7**

Given a string **str**, the task is to print all the permutations of **str**. A **permutation** is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For instance, the words ‘bat’ and ‘tab’ represents two distinct permutation (or arrangements) of a similar three letter word.
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