/**Question 6**
Given first term (a), common difference (d) and a integer N of the Arithmetic Progression series, the task is to find Nth term of the series.

**Example 1:**
Input : a = 2 d = 1 N = 5
Output : 6
The 5th term of the series is : 6
*/

// SOLUTION
// CPP Program to find nth term of
// Arithmetic progression
#include <bits/stdc++.h>
using namespace std;

int Nth_of_AP(int a, int d, int N)
{
    if(N== 1) return 1;
    else 
	return Nth_of_AP(a + (N - 1) * d);
	
}

