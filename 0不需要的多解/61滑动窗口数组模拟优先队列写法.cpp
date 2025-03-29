#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],l[N],r[N],dq[N];

int stk[N],top;

void solve()
{
	int n,k;cin>>n>>k;
	for(int i = 1;i <= n; ++i)cin>>a[i];
	
	int hh = 1,tt = 0;
	
	//求最大
	for(int i = 1;i <= n;++ i)
	{
		//以i为右端点，大小为k的区间，[i-k+1,i]
		
		//队列头的合法性
		while(hh <= tt && dq[hh] <= i-k)hh ++;
		//队尾的优越性
		while(hh <= tt && a[dq[tt]] <= a[i])tt --;
		
		dq[++ tt] = i;
		
		if(i >= k)cout<< a[dq[hh]] <<' ';
	}	
	cout<<'\n';
	hh = 1;tt = 0;//清空
		//求最小
	for(int i = 1;i <= n;++ i)
	{
		//以i为右端点，大小为k的区间，[i-k+1,i]
		
		//队列头的合法性
		while(hh <= tt && dq[hh] <= i-k)hh ++;
		//队尾的优越性
		while(hh <= tt && a[dq[tt]] >= a[i])tt --;
		
		dq[++ tt] = i;
		
		if(i >= k)cout<< a[dq[hh]] <<' ';
	}	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_--)solve();
	return 0;
}