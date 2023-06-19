/*<aside>
💡 **Question 4**

Given a Queue consisting of first **n** natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:

1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.
</aside>*/

// SOLUTION

#include <bits/stdc++.h>
using namespace std;

// Function to check if given queue element
// can be sorted into another queue using a
// stack.
bool checkSorted(int n, queue<int>& q)
{
	stack<int> st;
	int expected = 1;
	int fnt;

	// while given Queue is not empty.
	while (!q.empty()) {
		fnt = q.front();
		q.pop();

		// if front element is the expected element
		if (fnt == expected)
			expected++;

		else {
			// if stack is empty, push the element
			if (st.empty()) {
				st.push(fnt);
			}

			// if top element is less than element which
			// need to be pushed, then return false.
			else if (!st.empty() && st.top() < fnt) {
				return false;
			}

			// else push into the stack.
			else
				st.push(fnt);
		}

		// while expected element are coming from
		// stack, pop them out.
		while (!st.empty() && st.top() == expected) {
			st.pop();
			expected++;
		}
	}

	// if the final expected element value is equal
	// to initial Queue size and the stack is empty.
	if (expected - 1 == n && st.empty())
		return true;

	return false;
}

// Driven Program
int main()
{
	queue<int> q;
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	int n = q.size();

	(checkSorted(n, q) ? (cout << "Yes") :
						(cout << "No"));

	return 0;
}
