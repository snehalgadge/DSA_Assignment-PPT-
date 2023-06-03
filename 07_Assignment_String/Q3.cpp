/**Question 3**
Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
**Example 1:**
Input:num1 = "11", num2 = "123"
Output:"134"
*/

// SOLUTION
class Solution {
public:
void solve(string num1,string num2, string &ans, int carry,int i, int j){
        
        if(i<0 && j<0 && carry==0){
            return;
        }
        
        int first=0;
        int second=0;
        
        if(i>=0) first=num1[i]-'0';
        if(j>=0) second=num2[j]-'0';
        
        int sum = first+second+carry;
    
        int lastDigit = sum%10;
        carry = sum/10;
        
        ans.push_back(lastDigit+'0');
     
        solve(num1,num2,ans,carry,--i,--j);
    
    }
    string addStrings(string num1, string num2) {
        
        string ans ="";
        
        solve(num1,num2,ans,0,num1.size()-1,num2.size()-1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};