/**Question 1**
Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.
An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

**Example 1:**
Input: n = 27
Output: true
Explanation: 27 = 33
*/

// SOLUTION
bool isPower_of_Three(ll n)
{
    if (n <= 0)
        return false;
    if (n % 3 == 0)
        return isPower_of_Three(n / 3);
    if (n == 1)
        return true;
    return false;
}