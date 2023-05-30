/*Question 8
You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0*/

// SOLUTION
#include <iostream>
#include <unordered_map>
using namespace std;

void printElements(int arr[], int n, int k)
{

	int x = n/k;

	// Counting frequency of every element
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;

	for (auto it : mp)
		if (it.second > x)
			cout << it.first << endl;
}


int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4;

	printElements(arr, n, k);

	return 0;
}


