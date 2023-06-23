/*<aside>
💡 **Question 1**

Given a string `s`, *find the first non-repeating character in it and return its index*. If it does not exist, return `-1`.

</aside>*/

// SOLUTION
int firstUniqChar(string s) {
        queue<char>q;
        map<char,int>mp;
      for(int i=0; i<s.length(); i++){
        mp[s[i]]++;   
        q.push(s[i]); //adding the character in queue
      }
      char ans;
	  //In this loop we are checking for each & every character 
      while(!q.empty()){
        char temp = q.front();
        q.pop();
        if(mp[temp]<=1){ //if character is the first most character is occurring for once then store that character in your answer variable
          ans =temp;
          break; // break the loop we don't need to check further
        }
      }
	  //checking the index number of that character by taversing the string
      for(int i=0; i<s.length(); i++){
        if(ans==s[i]){
          return i;
          break;
        }
      }
      return -1;
    }