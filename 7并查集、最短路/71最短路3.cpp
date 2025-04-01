#include <bits/stdc++.h>
using namespace std;
const int N = 305 + 9;
using ll = long long;
const ll inf = 2e18;

ll n, m, q;

ll d[N][N];

void solve()
{
   cin >> n >> m >> q;
   for(int i = 1;i <= n; ++ i)
   	for(int j = 1;j <= n; ++ j)
   		d[i][j] = inf;
   for(int i = 1;i <= n; ++ i)d[i][i] = 0;
   
   for(int i = 1;i <= m; ++ i)
   {
   	ll x, y, w;cin >> x >> y >> w;
   	d[x][y] = min(d[x][y], w);
   }
   //floyd
   for(int k = 1;k <= n; ++ k)
   	for(int i = 1;i <= n; ++ i)
   		for(int j = 1;j <= n; ++ j)
   			if(d[i][k] + d[k][j] < d[i][j])
   				d[i][j] = d[i][k] + d[k][j];
   while(q --)
   {
   	int x, y;cin >> x >> y;
   	cout << (d[x][y] == inf ? -1 : d[x][y]) << '\n';
   }
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}