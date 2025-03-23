#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

int a[N],l[N],stk[N],top;
//stl的方法
//单调栈用来存储下标！
//top默认为0，此时栈为空的
//我的评价是要学会利用多家资源来学习，不然根本学不通透


{
	int n;cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	
	stack<int> stk;//栈内存放的是元素值
	
	for(int i = 1;i<=n;i++) 
	{
		//新加进来的和原先栈顶元素进行判定
		//新加进来的元素如果比原先栈顶元素小，意味着在后续遍历中，原先栈顶都不再满足要求
		//因此把原先栈顶元素给出栈
		while(stk.size() && stk.top() >= a[i]) stk.pop();//出栈操作
		//非空
		//空
		if(stk.empty()) l[i] = -1
		else l[i] = stk.top();//说明找不到比它小的数了
		
		stk.push(a[i]);//这是第二步，即入栈操作
	}
	
	for(int i = 1;i <= n; i++)cout<< l[i] <<' '; 
	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_ --)solve();
	return 0;
}