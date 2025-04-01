#include <bits/stdc++.h>
using namespace std;
const int N = 305 + 9;
using ll = long long;
const ll inf = 2e18;

ll d[N][N],n, m, q;//q次询问

//0x3f是4.5e18的大小，inf取4e18
void solve()
{
	cin>>n>>m>>q;
	memset(d,0x3f,sizeof d);//对字节操作
	//存边和权值,对边
	for(int i = 1;i <= m;i ++){
		ll u,v,w;cin>>u>>v>>w;
		d[u][v] = min(d[u][v],w);
	}
	//初始化，对点，自己到自己距离就是0
	for(int i = 1;i <= n;i ++) d[i][i] = 0;
	//取最优
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	
	while(q --){
		int u,v;cin>>u>>v;
		cout<<(d[u][v] >= inf ? -1:d[u][v])<<'\n';
	}
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}