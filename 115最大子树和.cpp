#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+10;
int w[N];
int dp[N];
vector<int> g[N];

void dfs(int x,int pre)
{
   dp[x]=w[x];
   for(auto&y:g[x])
   {
       if(y==pre)continue;
       dfs(y,x);
       dp[x]=max(dp[x],dp[x]+dp[y]);
   }
}
void solve()
{
   int n;cin>>n;
   for(int i = 1;i<=n;i++)cin>>w[i];
   for(int i = 1;i<=n;i++)
   {
       dp[i] = 0;
       g[i].clear();
   }
   for(int i = 1;i<n;i++)
   {
       int u,v;cin>>u>>v;
       g[u].push_back(v),g[v].push_back(u);
   }
   dfs(1,-1);
   cout<<*max_element(dp+1,dp+n+1)<<'\n';
}
int main()
{
   int T;cin>>T;
   while(T--)solve();
   return 0;
}