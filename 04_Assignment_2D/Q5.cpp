/**Question 5**
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.

Example 1:
Input: n = 5
Output: 2
*/

// SOLUTION
class Solution {
public:
    int arrangeCoins(int n) {
        long lo = 0, hi = n, mid, tmp;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            tmp = mid * (mid + 1) / 2;
            
            if (tmp == n) return mid;
            
            if (tmp <= n) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo-1;
    }
};