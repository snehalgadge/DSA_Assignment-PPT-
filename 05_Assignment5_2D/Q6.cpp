/**Question 6**

Given an integer array nums of length n where all the integers of nums are in the range 
[1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
**Example 1:**
Input: nums = [4,3,2,7,8,2,3,1]
Output:[2,3]
*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int arr_size = sizeof(numRay) / sizeof(numRay[0]);
    // count the frequency
    for (int i = 0; i < arr_size; i++) {
        numRay[numRay[i] % arr_size]
            = numRay[numRay[i] % arr_size] + arr_size;
    }
    cout << "The repeating elements are : " << endl;
    for (int i = 0; i < arr_size; i++) {
        if (numRay[i] >= arr_size * 2) {
            cout << i << " " << endl;
        }
    }
    return 0;
}