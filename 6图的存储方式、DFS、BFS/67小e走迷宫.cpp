//Code Here.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1009;
const ll inf = 4e18;
bitset<N> vis[N];
int mp[N][N], d[N][N];//地图和到起点的最短距离
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inmp(int x, int y){
 return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs(int sx, int sy){//结果存在vis里面！
 queue<pair<int, int> > q;
 d[sx][sy] = 0;//起点到起点最短距离是0，距离确定就标记，然后加入队列
 vis[sx][sy] = true;
 q.push({sx, sy});
 while(!q.empty()){
     int x = q.front().first;//存下横坐标
     int y = q.front().second;//存下纵坐标
     q.pop();//存下就要出队
     for(int i = 0;i < 4; ++ i){//访问上下左右的点
         int nx = dx[i] + x;
         int ny = dy[i] + y;
         if(inmp(nx, ny) && !mp[nx][ny] && !vis[nx][ny]){//在地图内，非障碍物，且未被访问
             d[nx][ny] = d[x][y] + 1;//走一个格子，离起点的距离+1
             vis[nx][ny] = true;//标记为已访问
             q.push({nx, ny});//将该边加入队列
         }
     }
  }
}

void solve(){
 cin >> n >> m;
 for(int i = 1;i <= n; ++ i)
     for(int j = 1;j <= m; ++ j)cin >> mp[i][j];
 bfs(1, 1);
 if(!vis[n][m])cout << -1 << '\n';//终点没有被访问
 else cout << d[n][m] << '\n';//终点到起点的距离
}

int main (){
 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 int q = 1;
 while(q--)solve();
 return 0;
}