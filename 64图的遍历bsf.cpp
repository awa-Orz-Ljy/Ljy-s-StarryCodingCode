#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

vector<int> g[N];
set<pair<int, int> > st;

bitset<N> vis;

void bfs(int s)
{
   queue<int> q;
   q.push(s);
   while(q.size())
   {
       int x = q.front();q.pop();
       if(vis[x])continue;
       vis[x] = true;
       for(const auto &y : g[x]){
           q.push(y);
       }
   }
}

int main()
{
   int n, m;cin >> n >> m;
   for(int i = 1;i <= m; ++ i)
   {
       int u, v;cin >> u >> v;
       if(u == v)continue;
       if(st.count({u, v}))continue;

       g[u].push_back(v);
       st.insert({u, v});
   }

   bfs(1);

   for(int i = 1;i <= n; ++ i)if(vis[i])cout << i << ' ';
   return 0;
}