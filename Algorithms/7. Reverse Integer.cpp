#include<iostream>
#include<string>
#include<climits>
#include"math.h"
using namespace std;

/*
考虑的问题：
1.100怎么办？1还是001？
2.原数字未超限，翻转后超限怎么办（最大，最小）？
*/

class Solution {
public:
	int reverse(int x) {
		//assume that your function returns 0 when the reversed integer overflows
		bool isNegative = x < 0 ? true : false;
		int leftPart = abs(x), opPart;
		long long  newNum = 0;
		while (leftPart!= 0){
			opPart = leftPart % 10;
			leftPart /= 10;
			newNum = newNum * 10 + opPart;
		}
		if (isNegative)
			newNum *= -1;
		if (newNum > INT_MAX)
			return 0;
		if (newNum < INT_MIN)
			return 0;
		return newNum;
	}
};

int main(){
	int i;
	Solution s;
	while (cin >> i)
		cout << s.reverse(i) << "\n";
	return 0;
}
