/**Question 3**
Given two strings word1 and word2, return *the minimum number of **steps** required to make* word1 *and* word2 *the same*.
In one **step**, you can delete exactly one character in either string.

**Example 1:**
**Input:** word1 = "sea", word2 = "eat"
**Output:** 2
*/

// SOLUTION
class Solution {
public:
    int solve(int i,int j,int &n,int &m,string &s1,string &s2,vector<vector<int>> &dp){
        if(i>=n){
            return (m-j);
        }else if(j>=m){
            return (n-i);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1,j+1,n,m,s1,s2,dp);
        }
        else{
            return dp[i][j] = 1+min(solve(i+1,j,n,m,s1,s2,dp),solve(i,j+1,n,m,s1,s2,dp));
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,word1,word2,dp);
    }
};