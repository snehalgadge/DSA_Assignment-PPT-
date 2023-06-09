/**Question 4**
Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.
There is only **one repeated number** in `nums`, return *this repeated number*.
You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
*/

// SOLUTION
int findDuplicate_bs(int[] nums) {
        int len = nums.length;
        int low = 1;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }