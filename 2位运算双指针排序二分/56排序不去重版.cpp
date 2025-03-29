#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;


int main()
{
	//set<int> st;//实现了去重，但是我现在不想去重
	//于是我知道了应该换成multiset即multi-set，这个数据类型不去重
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	multiset<int> a;
	int n;cin>>n;
	for(int i=0;i<=n;i++)
	{
		int x;cin>>x;
		a.insert(x);
	}
	for(auto &value : a)cout<<value<<' ';//auto这个很有用记得加&
	return 0;
}