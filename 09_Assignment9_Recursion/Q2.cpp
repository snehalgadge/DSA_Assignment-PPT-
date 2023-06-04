/**Question 2**
Given a number n, find the sum of the first natural numbers.

**Example 1:**
Input: n = 3 
Output: 6
*/

// SOLUTION
int findSum(int n)
{
   if (n % 2 == 0)
      return findSum(n / 2) * 1LL * findSum(n + 1);

   else
      return  findSum((n + 1) / 2) * 1LL * findSum(n);
}