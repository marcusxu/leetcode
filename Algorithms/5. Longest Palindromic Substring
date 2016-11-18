class Solution {
public:
	string longestPalindrome(string s) {
		//DP 自底向上的动态规划
		int length = s.length();
		int longestLen = 1, longestStart = 0;
		//一个字符的情况
		if (length <= 1)
			return s;
		//建立表
		bool **p = new bool*[length];
		for (int i = 0; i < length; ++i)
			p[i] = new bool[length];
		//初始化表
		for (int i = 0; i < length; ++i)
			for (int j = 0; j < length; ++j)
				p[i][j] = false;
		for (int i = 0; i < length; ++i)
			p[i][i] = true;
		//基本情况
		for (int i = 0; i < length - 1; ++i)
			if (s[i] == s[i + 1]){
				p[i][i + 1] = true;
				longestStart = i;
				longestLen = 2;
			}
		//DP
		for (int currLen = 3; currLen <= length; ++currLen)//第一重循环：步长
			for (int i = 0; i < length - currLen+1; ++i){//第二重循环：起点
				int j = i + currLen-1;
				if (s[i] == s[j] && p[i + 1][j - 1]){
					p[i][j] = true;
					if (currLen > longestLen){
						longestLen = currLen;
						longestStart = i;
					}
				}
			}
		//返回最大值
		return  s.substr(longestStart, longestLen);
	}
};
