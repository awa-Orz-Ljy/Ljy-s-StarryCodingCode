#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],l[N],r[N];

int stk[N],top;

void solve()
{
	int n,k;cin>>n>>k;
	for(int i = 1;i <= n; ++i)cin>>a[i];
	
		deque<int> dq;//存放下标
	
	//求最大
	for(int i = 1;i <= n;++ i)
	{
		//以i为右端点，大小为k的区间，[i-k+1,i]
		
		//队列头的合法性
		while(dq.size() && dq.front() <= i-k)dq.pop_front();
		//队尾的优越性
		while(dq.size() && a[dq.back()] <= a[i])dq.pop_back();
		
		dq.push_back(i);
		
		if(i >= k)cout<< a[dq.front()] <<' ';
	}	
	cout<<'\n';
	dq = deque<int>();//清空
		//求最小
	for(int i = 1;i <= n;++ i)
	{
		//以i为右端点，大小为k的区间，[i-k+1,i]
		
		//队列头的合法性
		while(dq.size() && dq.front() <= i-k)dq.pop_front();
		//队尾的优越性
		while(dq.size() && a[dq.back()] >= a[i])dq.pop_back();//越小越入栈
		
		dq.push_back(i);
		
		if(i >= k)cout<< a[dq.front()] <<' ';
	}	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_--)solve();
	return 0;
}