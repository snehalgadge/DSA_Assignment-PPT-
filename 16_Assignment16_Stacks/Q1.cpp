/*<aside>
💡 **Question 1**

Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than that of the current element. If there does not exist an answer for a position, then make the value ‘-1’.

</aside>*/

// SOLUTION
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>v{1, 1, 2, 3, 4, 2, 1};
	int n=v.size();
	map<int,int>mp;
	stack<int>s;
	for(auto it:v){
	mp[it]++;
	}
	for(int i=n-1;i>=0;i--)s.push(v[i]);
	for(int i=0;i<n;i++){
	int x=mp[v[i]];
	bool flag=1;
	stack<int>ss(s);
	while(!ss.empty()){
		if(mp[ss.top()]>x){
		cout<<v[i]<<" --> "<<ss.top()<<endl;
		flag=0;
		break;
		}
		ss.pop();
	}
	if(flag)cout<<v[i]<<" --> "<<-1<<endl;
	s.pop();
	}
	
	return 0;
}
