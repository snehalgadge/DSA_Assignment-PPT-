/*
**Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]
*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;
 
void printTwoElements(int arr[], int n){
 
  sort(arr,arr+n);
  cout << "The repeating element is ";
  for(int i=0;i<n-1;i++){
      if(arr[i]==arr[i+1]){
        cout<<arr[i]<<endl;
          break;
    }
  }
   
  cout << "and the missing element is ";
  for(int i=1;i<=n;i++){
      if(i!=arr[i-1]){
        cout<<i<<endl;
          break;
    }
  }
   
}
 
int main() {
 
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
    return 0;
}