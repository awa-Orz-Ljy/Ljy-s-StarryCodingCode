#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

int a[N],l[N],stk[N],top;
//stl的方法
//单调栈用来存储下标！
//top默认为0，此时栈为空的
//我的评价是要学会利用多家资源来学习，不然根本学不通透

void solve(){
	int n;cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	
	stack<int> stk;//栈内存放的是元素值
	
	for(int i = 1;i<=n;i++) 
	{
		//不符合条件
		while(!stk.empty() && stk.top() >= a[i]) stk.pop();
		//pop完，可能全空或者有符合条件的，就把答案放到l数组
		if(stk.empty()) l[i] = -1;
		else l[i] = stk.top();//说明top是符合小于a[i]的
		//要把数组的元素入栈来比较
		stk.push(a[i]);
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