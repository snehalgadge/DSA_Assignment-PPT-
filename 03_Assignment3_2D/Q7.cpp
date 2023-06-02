/*Question 7
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range
A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.
Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.
Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
*/
// SOLUTION
List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<String>();
        int next = lower;
        for (int i = 0; i < nums.length; i++) {
            if(lower == Integer.MAX_VALUE) return res;
            if (nums[i] < next) {
                continue;
            }
            if (nums[i] == next) {
                next++;
                continue;
            }
            res.add(getRange(next, nums[i] - 1));
            if(nums[i] == Integer.MAX_VALUE) return res;
            next = nums[i] + 1;
        }
        
        if (next <= upper) {
            res.add(getRange(next, upper));
        }
        return res;
    }
    
    String getRange(int n1, int n2) {
        return n1 == n2 ? String.valueOf(n1) : String.format("%d->%d" , n1, n2);
    }
        
   