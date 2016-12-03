#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(n2), TIME LIMIT EXCEEDED
/*
class Solution{
public:
	int maxArea(vector<int>& height) {
	int i,j,max=0,tmp;
	for(int i=0;i<height.size();++i)
		for(int j=i+1;j<height.size();++j){
			tmp=(j-i)*(height[i]<height[j]?height[i]:height[j]);
			max=tmp>max?tmp:max;
		}
	return max;
	}
};
*/

//O(nlogn+n) AC
class SolutionOld{
public:
	int maxArea(vector<int>& height) {
	//1.Sort O(nlogn)
	int size=height.size();
	vector<pair<int,int> > vec;
	for(int i=0;i<size;++i)
		vec.push_back(pair<int,int>(height[i],i));
	sort(vec.begin(),vec.end());
	//2.Travel O(n) 当前最矮的柱子，它的最大容积，是它的高*可达到的最长的长度
	int max=0,tmp,left=0,right=size-1;
	bool *flag=new bool[size];
	for(int i=0;i<size;++i) flag[i]=0;
	for(int i=0;i<vec.size();++i){
		tmp=vec[i].first*(vec[i].second-left>right-vec[i].second?vec[i].second-left:right-vec[i].second);
		max=max>tmp?max:tmp;
		flag[vec[i].second]=true;
		while(flag[left])	++left;
		while(flag[right])	--right;
		if(left>=right)		break;
	}
	return max;
	}
};

//O(n) from dicuss
//思路：先找到最宽的容器，想放最多的水，要比最宽的容器高
class Solution {
public:
    int maxArea(vector<int>& height) {
		int i=0,j=height.size()-1,max=0;
		while(i<j){
			int curHeight=min(height[i],height[j]);
			int tmp=(j-i)*curHeight;
			max=max>tmp?max:tmp;
			while(curHeight>=height[i]&&i<j) ++i;
			while(curHeight>=height[j]&&i<j) --j;
		}
		return max;
    }
};

int main() {
	Solution s;
	vector<int> h;
	int a;
	while(cin>>a)
		h.push_back(a);
	cout<<s.maxArea(h);
	return 0;
}
