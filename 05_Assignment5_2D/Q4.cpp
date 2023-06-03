/**Question 4**
Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*
- answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
- answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

**Example 1:**
**Input:** nums1 = [1,2,3], nums2 = [2,4,6]
**Output:** [[1,3],[4,6]]
*/

// SOLUTION
class Solution {
public:
    vector<int> set_diff(vector<int>& n1, vector<int>& n2){
        unordered_set<int> S1_minus_S2;
        unordered_set<int> S2;
        for(int x: n2)
            if (S2.find(x)==S2.end()) 
            S2.insert(x);
        for(int y: n1)
            if (S2.find(y)==S2.end()) 
            S1_minus_S2.insert(y);
        return vector<int> (S1_minus_S2.begin(), S1_minus_S2.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {set_diff(nums1, nums2), set_diff(nums2, nums1)};
    }
};
