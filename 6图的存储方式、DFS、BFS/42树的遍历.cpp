#include<bits/stdc++.h>
using namespace std;
const int N=50+4;
vector<int> g[N];
void dfs(int x)
{
  cout<< x <<' ';
  if(g[x].size()){
      for(auto &i:g[x]){
          dfs(i);
      }
  }
}
void bfs(int x){
  queue<int> q;
  q.push(x);
  while(q.size()){
      int k=q.front();
      q.pop();
      cout<< k <<' ';
      for(auto &i:g[k])q.push(i);
  }
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++){
      int x;cin>>x;
      g[x].push_back(i);
  }
  for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
  dfs(1);
  cout<<'\n';
  bfs(1);
  return 0;
}