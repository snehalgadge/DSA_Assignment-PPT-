/*<aside>
💡 **Question 5**

You are given a string **S**, the task is to reverse the string using stack.

</aside>*/

// SOLUTION
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void the_helper(string &str){

stack<char>s;

for(auto it:str)s.push(it);

str.clear();

while(!s.empty()){
	str.push_back(s.top());
	s.pop();
}
}
int main() {
//string we want to reverse.
string str = "GeeksQuiz";
//the function that make all necessary changes.
the_helper(str);
//finally return/output the reverse string
cout << "Reversed string is : " << str;
return 0;
}
