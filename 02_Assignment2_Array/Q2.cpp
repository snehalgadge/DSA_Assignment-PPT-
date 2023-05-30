/*Question 2
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3*/

// SOLUTION
#include<bits/stdc++.h>
using namespace std;

    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        
        int n=candyType.size();
        for(int i=0;i<n;i++)
        {
            s.insert(candyType[i]);
        }
        n/=2;
        if(s.size()<n)
        {
            return s.size();
        }
        return  n;
    }

    int main(){
        vector<int> candyType = {1,1,2,2,3,3};
        cout<<distributeCandies(candyType);

        return 0;
    }

