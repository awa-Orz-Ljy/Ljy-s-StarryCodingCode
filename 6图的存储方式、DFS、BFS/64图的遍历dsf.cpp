#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

vector<int> g[N];
set<pair<int, int> > st;

bitset<N> vis;//bool数组

// void dfs(int x)
// {
  // cout<< x <<' ';
  // if(g[x].size()){
      // for(auto &i:g[x]){
          // dfs(i);
      // }
  // }
// }
// 

void dfs(int x)
{
   if(vis[x])return;//遍历过了，跳过这个点
   vis[x] = true;
   for(const auto &y : g[x])//遍历 g[]
   {
       //y为x出点
       dfs(y);//递归
   }
}

int main()
{
   int n, m;cin >> n >> m;
   for(int i = 1;i <= m; ++ i)
   {
       int u, v;cin >> u >> v;
       if(u == v)continue;//环
       if(st.count({u, v}))continue;

       g[u].push_back(v);
       st.insert({u, v});
   }

   dfs(1);
   for(int i = 1;i <= n; ++ i)if(vis[i])cout << i << ' ';
   return 0;
}