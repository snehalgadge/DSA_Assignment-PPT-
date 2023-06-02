/*Question 2
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]*/

// SOLUTION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        int n = nums.size();
        // Sorting the array
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};