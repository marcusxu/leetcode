#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

//NOTE: the reversed integer might overflow case -2147447412 : answer should be 

class Solution {
public:
    bool isPalindrome(int x) {
		if(x==0)
			return true;
		if(x>INT_MAX||x<INT_MIN)
			return false;
        stack<int> s;
        queue<int> q;
        while(x!=0){
			s.push(x%10);
			q.push(x%10);	
			x/=10;
		}
		while(!s.empty()&&!q.empty()){
			if(s.top()!=q.front())
				return false;
			s.pop();
			q.pop();
		}
		return true;
    }
};

int main(){
	int i;
	Solution a;
	while(cin>>i){
		cout<<a.isPalindrome(i)<<'\n';
	}
	return 0;
}
		
