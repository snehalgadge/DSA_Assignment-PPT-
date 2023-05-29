/*
**Q6.** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true

*/

// SOLUTION
#include<bits/stdc++.h>
using namespace std;
    
bool containsDuplicate(vector<int> nums) {
 
    unordered_set<int> set;
    
    for(int i = 0; i<nums.size();i++){
        set.insert(nums[i]);
    }
    
    if(set.size() < nums.size())
        return true;
    
    return false;
}
    
int main () {
	    
    vector<int> nums {1, 2, 3, 1};
    
    bool res = containsDuplicate(nums);
    
    // printing the result
    if(res== 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}