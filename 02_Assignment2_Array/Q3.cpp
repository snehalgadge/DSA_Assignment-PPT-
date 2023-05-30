/*Question 3
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int findLHS(vector<int>& nums) {
      unordered_map<int, int> m;
      for (const int n : nums)
         ++m[n];
      int max_{ 0 };
      for (const auto & [ k, v ] : m) {
         auto it = m.find(k + 1);
         if (it != m.end())
            max_ = max(max_, v + it->second);
      }
      return max_;
   }
};
int main(){
   Solution ob;
   vector<int> v = {2,4,3,3,6,3,4,8};
   cout << (ob.findLHS(v));
   
   return 0;
}