#include<cmath>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

//NOTE: /*the reversed integer might overflow */
//      According to the problem, All negativr numbers are NOT palindrome
//      Which i think is unreasonabl

//Original Solution: bad, beats 4%
/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0)
			return true;
		//According to the problem, All negativr numbers are NOT palindrome
		//Which i think is unreasonable
		if (x<0)
			return false;
		if (x>INT_MAX || x<INT_MIN)
			return false;
		stack<int> s;
		queue<int> q;
		while (x != 0){
			s.push(x % 10);
			q.push(x % 10);
			x /= 10;
		}
		while (!s.empty() && !q.empty()){
			if (s.top() != q.front())
				return false;
			s.pop();
			q.pop();
		}
		return true;
	}
};

*/

//This Solution beats 96.8% !!
/*
*/
class Solution {
public:
	bool isPalindrome(int x) {
			return true;
		if (x < 0||x%10==0)
			return false;
		int y = 0;
		while (x > y){
			y = y * 10 + x % 10;
			x /= 10;
		}
		return x == y || x == y / 10;
	}
};

int main(){
	int i;
	Solution a;
	while (cin >> i){
		cout << a.isPalindrome(i) << '\n';
	}
	return 0;
}

