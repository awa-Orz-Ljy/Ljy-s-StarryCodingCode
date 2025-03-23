#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

struct Edge
{
   ll x, w;
   bool operator < (const Edge &u)const
   {
   	return w == u.w ? x < u.x : w > u.w;
   }
};

ll d[N];
bitset<N> intree;
vector<Edge> g[N];

void solve()
{
   memset(d, 0x3f, sizeof d);
   int n, m;cin >> n >> m;
   
   for(int i = 1;i <= m;++ i)
   {
   	ll u, v, w;cin >> u >> v >> w;
   	g[u].push_back({v, w});
   	g[v].push_back({u, w});
   }
   
   priority_queue<Edge> pq;
   
   pq.push({1, 0});
   d[1] = 0;
   ll ans = 0;
   
   while(pq.size())
   {
   	auto [x, w] = pq.top();pq.pop();
   	
   	if(intree[x]) continue;
   	intree[x] = true;
   	
   	if(x ^ 1) ans += w;
   	d[x] = 0;
   	
   	for(auto &[y ,w] : g[x])
   	{
   		if(!intree[y] && w < d[y])
   		{
   			d[y] = w;
   			pq.push({y, w});
   			
   		}
   	} 
   }
   for(int i = 1;i <= n;++ i) if(!intree[i]) ans = -1;
   cout << ans << '\n';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
   int _ = 1;
   while(_ --) solve();
   return 0;
}