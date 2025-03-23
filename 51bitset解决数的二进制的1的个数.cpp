#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3+9,M = 5e5 + 9;

void solve()
{
	int n;cin>>n;
	for(int i = 1;i<= n;i++)
	{
		int x;cin>>x;
		cout<<bitset<32>(x).count()<<' ';
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_--)solve();
	return 0;
}