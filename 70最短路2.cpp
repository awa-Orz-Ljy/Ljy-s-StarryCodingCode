#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
using ll = long long;
const ll inf = 2e18;

ll n, m;

struct Edge{
   ll x, w;
   //重载运算符
   bool operator < (const Edge &u)const{
   	if(w != u.w)return w > u.w;
   	return x < u.x;
   }
};

vector<Edge> g[N];

ll d[N];

void dijkstra(int st)
{
   //1.初始化
   for(int i = 1;i <= n; ++ i)d[i] = inf;
   //2.vis, pq
   bitset<N> vis;
   priority_queue<Edge> pq;
   pq.push({st, d[st] = 0});
   //3.开始松弛
   while(pq.size())
   {
   	int x = pq.top().x;
   	pq.pop();
   	if(vis[x])continue;
   	vis[x] = true;
   	
   	for(const auto &t : g[x])
   	{
   		ll w = t.w, y = t.x;
   		if(d[x] + w < d[y])
   		{
   			pq.push({y, d[y] = d[x] + w});
   		}
   	}
   }
}

void solve()
{
   cin >> n >> m;
   for(int i = 1;i <= m; ++ i)
   {
   	ll x, y, w;cin >> x >> y >> w;
   	g[x].push_back({y, w});
   }
   dijkstra(1);
   cout << (d[n] == inf ? -1 : d[n]) << '\n';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}