/*<aside>
💡 **Question 2**

Given an array **a** of integers of length **n**, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

</aside>*/

// SOLUTION

#include <iostream>
#include <stack>
using namespace std;

// Prints smaller elements on left side of every element
void printPrevSmaller(int arr[], int n)
{
	// Create an empty stack
	stack<int> S;

	// Traverse all array elements
	for (int i=0; i<n; i++)
	{
		// Keep removing top element from S while the top
		// element is greater than or equal to arr[i]
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		// If all elements in S were greater than arr[i]
		if (S.empty())
			cout << "_, ";
		else //Else print the nearest smaller element
			cout << S.top() << ", ";

		// Push this element
		S.push(arr[i]);
	}
}

int main()
{
	int arr[] = {1, 3, 0, 2, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}

