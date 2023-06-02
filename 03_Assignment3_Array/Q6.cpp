/*Question 6
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only
constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1*/

// SOLUTION
int findSingle(int A[], int ar_size)
{
    for (int i = 0; i < ar_size; i++) {
        int count = 0;
  
        for (int j = 0; j < ar_size; j++) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        if (count == 1) {
            return A[i];
        }
    }
    return -1;
}
  