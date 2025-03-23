#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int _=0;cin>>_;
	while(_ --)
	{
		int n;cin>>n;
		ll ans = 0;
		for(int i = 1;i <= n; i++)
		{
			int x;cin>>x;
			ans ^= x;//异或运算符
		}
		cout<<ans<<'\n';
	}
	return 0;
}