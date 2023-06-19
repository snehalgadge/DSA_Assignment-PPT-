/*<aside>
💡 **Question 8**

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

</aside>*/

// SOLUTION
class Solution {
public:
    int trap(vector<int>& h) {
             int i = 0;
            int j = h.size() - 1;
            int lm = 0;
            int rm = 0;
            int ans = 0;
            while (i <= j)
            {
                lm = max(lm, h[i]);
                rm = max(rm, h[j]);
                if (lm < rm)
                {
                    ans += lm - h[i];
                    i++;
                }
                else
                {
                    ans += rm - h[j];
                    j--;
                }
            }
            return ans;
    }
};