#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N];

void solve()
{
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(q--)
	{
		int x;cin>>x;
		int l = 0,r = n;
		while(l+1!=r)//标准判定，不需<=之类
		{
			int mid = (l+r) >> 1;
			if(a[mid]<x) l=mid;//左边界右移，产生新的mid，增大a[mid]以靠近x
			else r=mid;//右边界左移，产生新的mid，减小a[mid]以靠近x
		}
		if(a[r] == x)cout<<r<<' ';
		//上面的循环已经使得l和r贴得很近了哈哈哈
		//上面的条件知道 a[l]<x，判定a[r]是否=x即可
		else cout<<-1<<' ';
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;//意义不明哈哈
	while(_ --)solve();
	return 0;
}