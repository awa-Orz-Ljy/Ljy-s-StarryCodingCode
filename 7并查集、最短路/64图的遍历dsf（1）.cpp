#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];//邻接表
set<pair<int, int> > st;//存放的是一对，线段，细节空格避开>>歧义
bitset<N> vis;//bool数组记录搜索过的边
//输出从1出发能够到达的所有点
/*
void dfs(int x)
 {
 cout<< x <<' ';
   if(g[x].size()){
       for(auto &i:g[x]){
          dfs(i);
       }
   }
 }
*/
//这里不需要输出出点，递归的结果会保留在vis上，如下40多行那里
void dfs(int x){
   if(vis[x])return;//遍历过了，跳过这个点（出点可以表示边长）
   vis[x] = true;
   for(const auto &y : g[x]) 
   		dfs(y);//递归，y是x的出点
}
int main(){
   int n, m;cin >> n >> m;//n个点，m个边
   for(int i = 1;i <= m; ++ i){
       int u, v;cin >> u >> v;//输入的是uv线段
       if(u == v)continue;//环就要跳过
       if(st.count({u, v}))continue;//处理过了该边就要跳过
       g[u].push_back(v);//邻接表记录边
       st.insert({u, v});//插入边到set
   }
   dfs(1);
   for(int i = 1;i <= n; ++ i)
		if(vis[i]) cout << i << ' ';
   return 0;
}