#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3+9,M = 5e5 + 9;//每个数都可以取最大的100，且n取值在5e3以内，故做加法应该可以到5e5:)

int a[N];//装数字，最多5e3个

bool dp[M];//装结果，结果是到a[i]为止能够做加法取得的数字

void solve()
{
	int n;cin>>n;
	for(int i = 1;i<= n;i++)cin >> a[i];
	
	dp[0] = true;
	for(int i=1;i<=n;i++)
	{
		for(int j=5e5;j>=a[i];j--)//从右边开始抓到左边
		{
			dp[j] |= dp[j-a[i]];
		}
	}
	ll ans = 0;
	for(int i = 0;i <= 5e5; i++)if(dp[i]) ans++;
	cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_--)solve();
	return 0;
}