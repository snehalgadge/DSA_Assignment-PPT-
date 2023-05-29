/*
💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

**Example 1:**
Input: nums = [1,3,5,6], target = 5

Output: 2
*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;
 
int find_index(int arr[], int n, int K)
{
 
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == K)
            return mid;
        else if (arr[mid] < K)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end + 1;
}
 
// Main Function
int main()
{
    int nums[] = { 1,3,5,6 };
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    cout << find_index(nums, n, target) << endl;
    return 0;
}