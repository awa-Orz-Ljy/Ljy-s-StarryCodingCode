#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
const ll inf = 2e18;
struct Edge{
   ll x, w;
};

vector<Edge> g[N];
ll d[N], n;

void dijkstra(int st)
{
   //初始化d[]
   for(int i = 1;i <= n; ++ i)d[i] = inf;
   d[st] = 0;
   bitset<N> vis;
   //n次松弛
   for(int i = 1;i <= n; ++ i)
   {
   	//找松弛点（距离源点最近且未松弛过的点）
   	int x = 1;
   	for(int j = 1;j <= n; ++ j)
   		if(vis[x] || (!vis[j] && d[j] < d[x]))x = j;
   	
   	//进行一次松弛操作
   	for(const auto &[y, w] : g[x])
   		if(d[x] + w < d[y])d[y] = d[x] + w;
   	
   	vis[x] = true;
   }
}

void solve()
{
   int m;cin >> n >> m;
   while(m --)
   {
   	ll x, y, w;cin >> x >> y >> w;
   	g[x].push_back({y, w});
   }
   dijkstra(1);// => d[]
   cout << d[n] << '\n';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}