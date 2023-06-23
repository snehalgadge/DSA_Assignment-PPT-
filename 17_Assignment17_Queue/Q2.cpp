/*<aside>
💡 **Question 2**

Given a **circular integer array** `nums` of length `n`, return *the maximum possible sum of a non-empty **subarray** of* `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.

</aside>*/

// SOLUTION
  int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        int curr_max=nums[0],curr_min=nums[0],maxi=nums[0],mini=nums[0];
        for(int i=1;i<n;i++){
            curr_max=max(curr_max + nums[i], nums[i]);
            maxi=max(maxi, curr_max);

            curr_min=min(curr_min + nums[i], nums[i]);
            mini=min(mini, curr_min);
        }
        if(mini==sum) return maxi;
        return max(maxi, sum-mini);
    }