/**Question 8**
An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.
Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

**Example 1:**
Input:changed = [1,3,4,2,6,8]
Output: [1,3,4]
*/

// SOLUTION
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
           vector<int> ans;        
        if(changed.size()&1) return ans; 
        
        vector<int> cnt(1e5+1, 0);
        
        for(int i=0;i<changed.size();i++){
            cnt[changed[i]]++;
        }
        
        for(long long i=0;i<1e5+1;i++){
            while(i*2<1e5+1 && cnt[i]>0 && cnt[i*2]>0){
                cnt[i]--;
                cnt[2*i]--;
                ans.push_back(i);
            }
        }
        
        for(int i=0;i<1e5+1;i++){
            if(cnt[i]>0){
                vector<int> temp;
                return temp;
            }
        }
        return ans;
    }
};