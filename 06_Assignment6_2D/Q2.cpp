/**Question 2**
You are given an m x n integer matrix matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.
You must write a solution in O(log(m * n)) time complexity.

**Example 1:**
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

// SOLUTION
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row  = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = (row*col)-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            int num = matrix[mid/col][mid%col];
            
            if(num==target) return true;
            
            if(num<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
            return false;
    }
};