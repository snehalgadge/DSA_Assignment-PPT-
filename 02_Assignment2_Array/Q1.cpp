/*Question 1
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

Example 1:
Input: nums = [1,4,3,2]
Output: 4*/

// SOLUTION
#include <iostream>
#include <algorithm>

using namespace std;

int arrayPairSum(int[] nums) {
    sort(nums.begin(), nums.end());
    int total = 0;
    for (int i = 0; i < nums.length(); i += 2) {
        total += nums[i];
    }
    return total;
}

int main() {
    int nums[] = {1, 4, 3, 2};
    cout << arrayPairSum(nums) << endl;

    return 0;
}
