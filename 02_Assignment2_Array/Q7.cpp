/*Question 7
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true*/

// SOLUTION

#include <iostream>
#include <algorithm>
using namespace std;

bool check_monotonic(int array[], int size)
{

	if (is_sorted(array, array + size, greater<int>()))
		return true;

	if (is_sorted(array, array + size))
		return true;

	return false;
}


int main()
{
	int array1[] = { 7, 5, 3, 1 };
	int array2[] = { 4, 0, 3, 1 };
	int array3[] = { 5, 4, 3 };

	int size1 = sizeof(array1) / sizeof(array1[0]);
	int size2 = sizeof(array2) / sizeof(array2[0]);
	int size3 = sizeof(array3) / sizeof(array3[0]);

	if (check_monotonic(array1, size1))
		cout << "Is Monotonic ?: true\n";
	else
		cout << "Is Monotonic ?: false\n";

	if (check_monotonic(array2, size2))
		cout << "Is Monotonic ?: true\n";
	else
		cout << "Is Monotonic ?: false\n";

	if (check_monotonic(array3, size3))
		cout << "Is Monotonic ?: true\n";
	else
		cout << "Is Monotonic ?: false\n";

	return 0;
}
