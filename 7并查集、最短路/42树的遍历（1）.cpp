#include<bits/stdc++.h>
using namespace std;
const int N=50+4;
//dfs用的是vector，bfs用的是队列queue（双端deque，优先priority_queue，普通queue）
//子节点用i的23456789来表示
//输出树的dfs，bfs的遍历顺序
vector<int> g[N];
void dfs(int x){
  //递归会输出很多次，这是遍历的核心
  cout<< x <<' ';
  //非空就继续搜索本身节点
  if(!g[x].empty()){
      for(auto &i:g[x]){
          dfs(i);
      }
  }
}
void bfs(int x){
  //创建队列并且x入队,且无需递归
  queue<int> q;
  q.push(x);
  while(!q.empty()){
  	//保留前端,再pop掉,再输出前端
      int k=q.front();//此处命名了父节点为k，与x无异
      q.pop();
      cout<< k <<' ';
      //循环里面输出k的子节点，即x的
      for(auto &i:g[k]) q.push(i);//继续入队（子节点）
  }
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;cin>>n;//点的个数
  for(int i=2;i<=n;i++){
      int x;cin>>x;//父节点
      g[x].push_back(i);//邻接表，记录父节点和子节点！
  }
  for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
  dfs(1);
  cout<<'\n';
  bfs(1);
  return 0;
}