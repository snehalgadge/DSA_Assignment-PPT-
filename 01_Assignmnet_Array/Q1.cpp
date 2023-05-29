/*
Q1. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

**Example:**
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]
**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1][
*/

// SOLUTION
#include<bits/stdc++.h>
using namespace std;

// 1)BRUTE FORCE
/*
  Time Complexity: O(n^2)
  Space Complexity: O(1)
*/
vector<int> sum(int n, vector<int> &nums, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}


// 2)Better
/*
  Time Complexity: O(n)
  Space Complexity: O(n)
*/
vector<int> sum(int n, vector<int> &nums, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}


// 3)Optimal
/*
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
*/
vector<int> sum(int n, vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            ans.push_back(left);
            ans.push_back(right);
        }
        else if (sum < target) left++;
        else right--;
    }
    return ans;
}



// main function
int main()
{
    int n = 5;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = sum(n, nums, target);
    cout << "The target"<<target<<" will get by adding: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
