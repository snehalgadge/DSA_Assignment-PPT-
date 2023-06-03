/**Question 4**
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is **maximized**. Return *the maximized sum*.

**Example 1:**
Input: nums = [1,4,3,2]

Output: 4
*/

// SOLUTION
class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                ans = ans + nums[i];
            }
        }
        return ans;
    }
};
