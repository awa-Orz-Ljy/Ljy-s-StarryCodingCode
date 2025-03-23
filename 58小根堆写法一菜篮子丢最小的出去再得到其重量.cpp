#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

struct cmp
{
	bool operator ()(const ll &u,const ll &v)const
	{
		return u>v;//如果是<则是大根堆写法
	}
};

void solve()
{
	int q;cin>>q;
	priority_queue<ll, vector<ll>, cmp> pq;//小根堆
	
	ll sum = 0;
	while(q --)
	{
		int op;cin>>op;
		if(op == 1)
		{
			ll x;cin>>x;
			pq.push(x);
			sum += x;
		}
		else if(pq.size())
		{
			sum -= pq.top();
			pq.pop();
		}
	}
	cout<<sum<<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_--) solve();
	return 0;
}