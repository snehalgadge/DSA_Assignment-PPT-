/**Question 8**
Given an array, find a product of all array elements.

**Example 1:**
Input  : arr[] = {1, 2, 3, 4, 5}
Output : 120
*/

// SOLUTION
int product(int a[], int n)
{
    if (n == 0)
        return(a[n]);
    else
        return (a[n] * product(a, n - 1));
}
