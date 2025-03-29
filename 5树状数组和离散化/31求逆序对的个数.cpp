#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 8e18, p = 998244353;
const int N = 2e5 + 9;

ll a[N],t[N];

vector<int> X;

int bin(int x)
{
	return lower_bound(X.begin(),X.end(),x) - X.begin() +1;
}

int lowbit(int x){return x & -x;}

void update(int k,int x)//上
{
	for(int i = k;i <= X.size(); i += lowbit(i)) t[i] +=x;
}

int getsum(int k)//下
{
	int res = 0;
	for(int i = k;i > 0;i-= lowbit(i)) res += t[i];
	return res;
}

void solve()
{
	int n;cin>>n;
	for(int i = 1;i <= n; ++ i)
	{
		cin>> a[i];
		X.push_back(a[i]);
	}
	//排序去重
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	//[1,2,3,6]
	
	ll ans = 0;
	for(int i = 1;i <= n;++i)
	{
		ans += 1ll * getsum(X.size()) - getsum(bin(a[i]));//排过序了，
		//此时前者为全部元素的个数之和，后者为小于a[i]的元素之和，相减不言而喻
		update(bin(a[i]),1);
	}
	cout << ans <<'\n';
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_--)solve();
	return 0;
}	