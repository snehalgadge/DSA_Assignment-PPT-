/**Question 2**
A peak element is an element that is strictly greater than its neighbors.
Given a **0-indexed** integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.
You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in `O(log n)` time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

// SOLUTION
int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(mid==0){
                return nums[0] >= nums[1] ? 0 : 1;
            }
            if (mid == end){
                return nums[end - 1] >= nums[end - 2] ? end - 1 : end - 2;
            }

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            if(nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }