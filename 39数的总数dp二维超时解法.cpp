#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3+9;//每个数都可以取最大的100，且n取值在5e3以内，故做加法应该可以到5e5:)

int a[N];

bool dp[N][N];

void solve()
{
	int n;cin>>n;
	for(int i = 1;i<= n;i++)cin >> a[i];
	
	dp[0][0] = true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j >= a[i])dp[i][j] |= dp[i-1][j-a[i]];
		}
	}
	ll ans = 0;
	for(int i = 0;i <= 5e3; i++)if(dp[n][i]) ans++;
	cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_--)solve();
	return 0;
}