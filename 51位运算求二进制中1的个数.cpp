#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

int f(int x)
{
	int res = 0;
	while(x)
	{
		if(x & 1)res ++;
		x>>=1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n;cin>>n;
	for(int i=1;i <=n;i++)
	{
		int x;cin>>x;
		cout<<f(x)<<' ';
	}
	return 0;
}