/*Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6*/

// SOLUTION
// A C++ program to find a maximum product of a
// triplet in array of integers
#include <bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int n)
{
	if (n < 3)
		return -1;

	int max_product = INT_MIN;

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				max_product = max(max_product,
						arr[i] * arr[j] * arr[k]);

	return max_product;
}


int main()
{
	int arr[] = { 10, 3, 5, 6, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int max = maxProduct(arr, n);

	if (max == -1)
		cout << "No Triplet Exists";
	else
		cout << "Maximum product is " << max;

	return 0;
}
