/**Question 2**
Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.
A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).
Example 1:
Input:num = "69"
Output:true
*/

// SOLUTION
class Solution {
    bool isStrobogrammatic(String num) {
        map<char, char> mapp
        mapp.put('6', '9');
        mapp.put('9', '6');
        mapp.put('0', '0');
        mapp.put('1', '1');
        mapp.put('8', '8');
        int l = 0, r = num.length() - 1;
        while (l <= r) {
            if (!mapp.containsKey(num.charAt(l))) return false;
            if (mapp.get(num.charAt(l)) != num.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}

