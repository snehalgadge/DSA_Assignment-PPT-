/**Question 6**
Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.
Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.
Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.
You must write an algorithm that runs in `O(log n) time.`

**Example 1:**
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

// SOLUTION
int findMin(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int mini=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            mini=min(mini,arr[mid]);
            mini=min(mini,arr[l]);
            if(arr[mid]>=arr[l]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return mini;
    }