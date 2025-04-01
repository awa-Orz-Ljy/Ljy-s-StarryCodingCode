#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
const ll inf = 2e18;
struct Edge{
   ll x, w;
};//存出点和权值

vector<Edge> g[N];
ll d[N], n;

void dijkstra(int st)//起点开始寻找最短路
{
   //初始化d[]
   for(int i = 1;i <= n; ++ i)d[i] = inf;
   d[st] = 0;//起点到起点的最短路径长度是0
   bitset<N> vis;//记录是否拓展过
   
   //找出最近的点
   for(int i = 1;i <= n; ++ i){
   		int x = 1;//起点是1，有n个点
   		for(int j = 1;j <= n; ++ j){//遍历vis数组来更新距离最近的点
   			if(vis[x] || (!vis[j] && d[j] < d[x])) x = j;
   		}
   	vis[x] = true;
	//此时d[u]为最优
   		for(const auto &[y, w] : g[x]){
   			if(d[x] + w < d[y])d[y] = d[x] + w;//更新dy
   		}
   }
}

void solve(){
   int m;cin >> n >> m;
   while(m --){//边的个数
   	ll x, y, w;cin >> x >> y >> w;
   	g[x].push_back({y, w});
   }
   dijkstra(1);// => d[]
   cout << (d[n] == inf ? -1 : d[n]) << '\n';//n到起点的最短距离
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}