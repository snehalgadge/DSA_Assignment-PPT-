/**Question 5**
Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/

// SOLUTION
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int lb=0,ub=nums2.size()-1,mid=0;
            while(lb<=ub)
            {
                mid=lb+(ub-lb)/2;
                if(nums2[mid]==nums1[i])
                {
                    if(find(ans.begin(),ans.end(),nums2[mid])!=ans.end())
                        break;
                    ans.push_back(nums2[mid]);
                    break;
                }
                else if(nums2[mid]<nums1[i])
                    lb=mid+1;
                else
                    ub=mid-1;
            }
        }
        return ans;
    }

