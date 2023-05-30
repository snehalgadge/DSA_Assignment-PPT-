/*Question 4
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true*/

// SOLUTION

class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n==0){
            return true;
        }
        for(int i=0;i<f.size();i++){
            if (f[i]==0)
            {
                int sum=0;
                int fin=0;
                if(i==0){
                    sum+=1;
                }
               
                while (f[i]==0 && i<f.size()){
                    sum+=1;
                    i++;
                    if(i==f.size()){
                        sum+=1;
                        break;
                    }
                }
                

                if (sum>0){
                    if( sum%2==0){
                        fin=(sum/2)-1;
                        if(fin>=n){
                            return true;
                        }
                        else{
                            n-=fin;
                        }
                    }
                    else if(sum>2 and sum%2!=0){
                        fin=sum/2;
                        if(fin>=n){
                            return true;
                        }
                        else{
                            n-=fin;
                        }
                    }
                }
                
                i--;
            
            }
            
            
        }
        return false;
    }
};