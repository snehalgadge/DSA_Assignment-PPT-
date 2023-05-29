/*Q2. Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.
**Example :**
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

**Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)[
*/

// SOLUTION

#include<bits/stdc++.h>
using namespace std;

//1)BRUTE FORCE
void remove_all_occurrence(int arr[],int target,int n)
{
    int cnt = 0; 
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        cnt++;
    }
    int new_arr[n - cnt];
    int ind = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != target)
        {
            new_arr[ind] = arr[i];
            ind++;
            }
    }
	
int m = (sizeof(new_arr) /sizeof(new_arr[0]));
for(int i = 0; i < m; i++)
{
	cout << new_arr[i] << " ";
}
return;
}


//2) Optimal 
void remove_all_occurrence(int arr[],int target,int n)
{
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] != target)
    {
      arr[i - cnt] = arr[i];
    }
    else
    {
      cnt++;
    }
  }
   
  for(int i = 0; i < (n - cnt); i++)
  {
    cout << arr[i] << " ";
  }
  return; 
}



// Main function
int main()
{
    int nums[]={3,2,2,3};
    int val = 3;
    int n = (sizeof(nums) /sizeof(nums[0]));
    remove_all_occurrence(nums, val, n);
    return 0;
}

