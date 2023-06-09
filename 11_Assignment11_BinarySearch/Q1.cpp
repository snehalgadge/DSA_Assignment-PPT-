/**Question 1**

Given a non-negative integer `x`, return *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be **non-negative** as well.
You **must not use** any built-in exponent function or operator.
- For example, do not use `pow(x, 0.5)` in c++ or `x ** 0.5` in python.

**Example 1:**
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
*/

// SOLUTION
int mySqrt(int x) {
       long long s=0, e=x, ans, mid;   
        while(s<=e){             
            mid=(s+e)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x){             
                s=mid+1;       
                ans=mid; 
            }
            else e=mid-1;       
        }
        return ans;   
 
    }