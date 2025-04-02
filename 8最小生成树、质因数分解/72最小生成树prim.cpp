#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

struct Edge
{
   ll x, w;
   bool operator < (const Edge &u)const{
   	return w == u.w ? x < u.x : w > u.w;
   }
};

ll d[N];
bitset<N> intree;
vector<Edge> g[N];

void solve()
{
	//初始化
   memset(d, 0x3f, sizeof d);
   int n, m;cin >> n >> m;
   //存边
   for(int i = 1;i <= m;++ i)
   {
   	ll u, v, w;cin >> u >> v >> w;
   	g[u].push_back({v, w});
   	g[v].push_back({u, w});
   }
   //优先队列
   priority_queue<Edge> pq;
   pq.push({1, 0});
   d[1] = 0;
   ll ans = 0;
   //维护intree找点 
   while(!pq.empty()){
   		int x = pq.top().x;
  	 	pq.pop();
   	
   		if(intree[x]) continue;
   		intree[x] = true;
   		//不是起点就更新答案
   		if(x ^ 1) ans += d[x];
	   	d[x] = 0;
	   	//对gx未被拓展且符合小的要求就更新d
	   	for(auto &[y ,w] : g[x]) 
	   	{
	   		if(!intree[y] && w < d[y])
	   		{
	   			d[y] = w;
	   			pq.push({y, w});
	   			
	   		}
	   	} 
   }
   //不存在的点
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