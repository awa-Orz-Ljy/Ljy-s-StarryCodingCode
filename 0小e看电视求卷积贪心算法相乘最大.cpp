#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N],b[N];

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++)cin>>b[i];
	
	sort(a+1,a+1+n),sort(b+1,b+1+n);
	ll ansMax = 0,ansMin = 0;
	for(int i =1;i<=n;i++)ansMax += a[i]*b[i];
	for(int i =1;i<=n;i++)ansMin += a[i]*b[n+1-i];
	cout<<ansMin<<' '<<ansMax<<'\n';
	
	return  0;
}