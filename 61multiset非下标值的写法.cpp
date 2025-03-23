#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],dq[N],mi[N],mx[N];

void solve()
{
	int n,k;cin>>n>>k;
	for(int i = 1;i <= n; ++i)cin>>a[i];
	
	multiset<int> st;
	
	for(int i=1;i <= n;++i)
	{
		st.insert(a[i]);
		if(i >= k)mi[i] = a[*st.begin()],mx[i] = a[*st.rbegin()],st.erase(st.find(a[i-k+1]));
	}
	
	for(int i = k;i <= n;++i)cout<<mx[i]<<"\n"[i == n];
	for(int i = k;i <= n;++i)cout<<mi[i]<<"\n"[i == n];
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_--)solve();
	return 0;
}