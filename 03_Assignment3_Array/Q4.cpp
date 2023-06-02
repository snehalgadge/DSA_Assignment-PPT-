/*Question 4
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2*/

// SOLUTION
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (high+low)/2;

            if(nums[mid] == target){
                return mid;
                break;
            }
            if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};