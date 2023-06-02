/*Question 5
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]*/

// SOLUTION
void plus_one(vector<int> &digits,int n)
{
    reverse(digits.begin(),digits.end());
    int carry=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            digits[i]+=(1+carry);

        else if(carry!=0)
            digits[i]+=carry;
    
        carry=digits[i]/10;
        
        if(carry!=0)
            digits[i]=digits[i]%10;
    }
  
    if(carry!=0)
        digits.push_back(carry);
    
    reverse(digits.begin(),digits.end());
}
