/**Question 7**

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
*/

// SOLUTION
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {      
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count =0;
        int total =n*n; 
        int startingrow=0;
        int startingcol=0;
        int endingrow=n-1;
        int endingcol=n-1;
        
        while(count<total)
        {
            for(int i=startingcol;count<total && i<=endingcol; i++)
            {
                count++;
                ans[startingrow][i]=count;
                
            }
            startingrow++;
            
            for(int i=startingrow;count<total && i<=endingrow; i++)
            {
            
                count++;
                ans[i][endingcol]=count;
            }
            endingcol--;
            
            for(int i=endingcol;count<total && i>=startingcol; i--)
            {
                 count++;
                ans[endingrow][i]=count;
            }
            endingrow--;
            
            for(int i=endingrow;count<total && i>=startingrow; i--)
            {
                 count++;
                ans[i][startingcol]=count;
            
            }
            startingcol++;
        }    
        return ans;
    }
};