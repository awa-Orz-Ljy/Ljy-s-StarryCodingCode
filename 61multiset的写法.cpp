#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],dq[N],mi[N],mx[N];

struct cmp
{
	bool operator ()(const int &u,const int &v)const
	{
		return a[u] < a[v];
	}
};

void solve()
{
	int n,k;cin>>n>>k;
	for(int i = 1;i <= n; ++i)cin>>a[i];
	
	multiset<int,cmp> st;
	
	for(int i=1;i <= n;++i)
	{
		st.insert(i);
		while(*st.begin() <= i-k)st.erase(st.begin());
		while(*st.rbegin() <= i-k)st.erase(prev(st.end()));//可以改成-- st.end()的
		if(i >= k)mi[i] = a[*st.begin()],mx[i] = a[*st.rbegin()];
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