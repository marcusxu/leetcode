#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		//空字符串
		if (str.size() == 0)
			return 0;
		//变量声明
		int len = str.length();
		int result = 0;
		int p = 0;
		bool isNegative = false;
		//开头的空格
		while (str[p] == ' ')
			++p;
		//正负号，只能有一个符号
		if (str[p] == '-' || str[p] == '+'){
			if (str[p] == '-')
				isNegative = true;
			++p;
		}
		//组合数字，遇到空格或非数字停止
		while (p<len){
			if (str[p]<'0' || str[p]>'9')
				break;
			int tmp= result * 10 + str[p] - '0';
			//如果超出极值,tmp：1.负数 2.最后一位不是刚加进去的
			if (tmp < 0||tmp%10!=str[p]-'0')
				return isNegative ? INT_MIN:INT_MAX;
			result = tmp;
			++p;
		}
		//处理负数
		if (isNegative)
			result *= -1;
		return result;
	}
};

int main(){
	string s;
	Solution a;
	while (cin >> s){
		cout << a.myAtoi(s) << '\n';
	}
	return 0;
}
//9223372036854775809
//"    10522545459"