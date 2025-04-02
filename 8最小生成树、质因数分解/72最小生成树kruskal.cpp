#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

struct Edge
{
   ll u,v,w;
   bool operator < (const Edge &m)const{
		if(w != m.w)return w < m.w;
		if(u != m.u)return u < m.u;
		return v < m.v;
   }
};

ll d[N];
 
int pre[N];

int root(int x){return pre[x] = (pre[x] == x ? x : root(pre[x]));}

void solve()
{
	//初始化
   int n, m;cin >> n >> m;
   memset(d, 0x3f, sizeof d);
   vector<Edge> es;
   //存边
   for(int i = 1;i <= m;++ i)
   {
   	ll u, v, w;cin >> u >> v >> w;
   	es.push_back({u,v, w});
   }
   sort(es.begin(),es.end());
   //做更新
   ll ans = 0;
   for(int i = 1;i <= n;i ++) pre[i] = i;
   for(auto &[u,v,w] : es){
   	if(root(u) == root(v)) continue;
   	//重复的边
   	ans += w;
   	pre[root(u)] = root(v);
   }
   //不存在的点
   for(int i = 1;i < n;++ i) if(root(i) != root(i + 1)) ans = -1;
   cout << ans << '\n';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
   int _ = 1;
   while(_ --) solve();
   return 0;
}