/**Question 3**
****Given a set represented as a string, write a recursive code to print all subsets of it. The subsets can be printed in any order.

**Example 1:**
Input :  set = “abc”
Output : { “”, “a”, “b”, “c”, “ab”, “ac”, “bc”, “abc”}
*/

// SOLUTION
void solve(vector<int>& nums,vector<vector<int>> &ans, vector<int> temp,int index){
            
            if(index==nums.size()){
                ans.push_back(temp);
            
                return;
            }
            
            temp.push_back(nums[index]);
            solve(nums,ans,temp,index+1);
            
            temp.pop_back();           
            solve(nums,ans,temp,index+1);
            
        }