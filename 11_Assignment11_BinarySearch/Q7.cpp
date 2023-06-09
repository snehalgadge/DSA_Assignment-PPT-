/**Question 7**
Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.
If `target` is not found in the array, return `[-1, -1]`.
You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

// SOLUTION
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size()-1;
        int start = 0;
        int end = n;

        while(start<=end){
            int mid = (start+end)/2;

            if(nums[mid] == target){
                int temp = mid;

                while(mid > 0 && nums[mid-1] == target) 
                mid--;
                start = mid;

                while(temp < n && nums[temp+1] == target)
                temp++;
                end = temp;

                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
            else if(nums[mid] < target)
            start = mid+1;

            else
            end = mid-1;
        }

        ans.push_back(-1);
        ans.push_back(-1);

        return ans;
    }
