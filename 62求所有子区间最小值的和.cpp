#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],l[N],r[N];

int stk[N],top;

void solve()
{
	int n;cin>>n;
	for(int i = 1;i <= n; ++i)cin>>a[i];
	
	//先求l[] < a[i]
	for(int i = 1;i<=n;++i)
	{
		while(top && a[stk[top]] >= a[i])top--;//入栈的a[i]更优秀，更小,把栈顶给丢了
		//此时栈顶就是l[i]
		if(!top)l[i] = 0;//区间之外的数字
		else l[i] = stk[top];
		
		stk[++top] = i;//把i入栈
	}
	
	top = 0;
	
	//在求r[] <= a[i],因为遇到相等的数字的时候要分配给右边的数字
	for(int i = n;i>=1;--i)
	{
		while(top && a[stk[top]] > a[i])top--;//入栈的a[i]更优秀，更小,把栈顶给丢了
		//此时栈顶就是l[i]
		if(!top)r[i] = n+1;//区间之外的数字
		else r[i] = stk[top];
		
		stk[++top] = i;//把i入栈
	}
	ll ans = 0;
	for(int i = 0;i <= n; ++i)ans += a[i]*(r[i] - i)*(i - l[i]);
	cout<< ans <<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_--)solve();
	return 0;
}