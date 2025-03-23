#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

void solve()
{
	map<string,int> mp;//mp[s]表示s的数量
	
	vector<string> v;//表示字符串的出现顺序
	
	int n;cin>>n;
	
	for(int i = 1;i<=n;i++)
	{
		string s;cin>>s;
		if(mp.count(s)) mp[s] ++;
		else v.push_back(s),mp[s] = 1;//创建二元组呗
	}
	
	for(auto &i : v)cout<<i<<' '<<mp[i]<<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--) solve();
	return 0;
}