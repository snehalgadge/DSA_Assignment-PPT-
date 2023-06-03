/**Question 5**

Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

**Example 1:**
**Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
**Output:** 2
*/

// SOLUTION
class Solution {
public:
    bool isValid(vector<int>&arr,int target,int d){
        
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            
            int mid = low + (high - low)/2;
            if(abs(arr[mid] - target) <= d){
                return false;
            }
            else if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        
        int cnt = 0;
        for(auto num:arr1){
           if(isValid(arr2,num,d)){
               cnt++;
           } 
        }
        
        return cnt;
    }
};  
