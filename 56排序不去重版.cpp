#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;


int main()
{
	//set<int> a;//实现了去重，但是我现在不想去重
	//于是我知道了应该换成multiset即multi-set
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	multiset<int> a;
	int n;cin>>n;
	for(int i=0;i<=n;i++)
	{
		int x;cin>>x;
		a.insert(x);
	}
	for(auto &value : a)cout<<value<<' ';
	return 0;
}