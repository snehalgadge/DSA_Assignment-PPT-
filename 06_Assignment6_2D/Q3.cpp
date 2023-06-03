/**Question 3**
Given an array of integers arr, return *true if and only if it is a valid mountain array*.
Recall that arr is a mountain array if and only if:
- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

**Example 1:**
Input:arr = [2,1]
Output:false
*/

// SOLUTION
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
    int n=arr.size();
    if(n<3)
        return false;

    int count=0;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]<arr[i-1]&&arr[i]<arr[i+1] || arr[i]==arr[i-1])
            return false;
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1] )
            count++;
    }
    if(count!=1)
        return false;
    return true;

    }
};