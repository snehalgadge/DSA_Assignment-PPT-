/*Question 1
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
*/

// SOLUTION
int solution(vector<int>& arr, int x)
{
    sort(arr.begin(), arr.end());

    int closestSum = 1000000000;
    for (int i = 0; i < arr.size() - 2; i++) {
 
        int ptr1 = i + 1, ptr2 = arr.size() - 1;
 
        while (ptr1 < ptr2) {
 
            int sum = arr[i] + arr[ptr1] + arr[ptr2];
             
              if (sum == x)
              return sum;
        
            if (abs(x - sum) < abs(x - closestSum)) {
                closestSum = sum;
            }
 
            if (sum > x) {
                ptr2--;
            }
            else {
                ptr1++;
            }
        }
    }

    return closestSum;
}