/**Question 3**
****Given a positive integer, N. Find the factorial of N. 

**Example 1:**
Input: N = 5 
Output: 120
*/

// SOLUTION
unsigned int factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
  