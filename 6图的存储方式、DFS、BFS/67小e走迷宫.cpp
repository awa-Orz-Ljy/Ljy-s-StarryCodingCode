//Code Here.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1009;
const ll inf = 4e18;
bitset<N> vis[N];
int mp[N][N], d[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inmp(int x, int y)
{
 return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs(int sx, int sy)
{
 queue<pair<int, int> > q;
 d[sx][sy] = 0;
 vis[sx][sy] = true;
 q.push({sx, sy});
 while(q.size())
 {
     int x = q.front().first;
     int y = q.front().second;
     q.pop();
     for(int i = 0;i < 4; ++ i)
     {
         int nx = dx[i] + x;
         int ny = dy[i] + y;
         if(inmp(nx, ny) && !mp[nx][ny] && !vis[nx][ny])
         {
             d[nx][ny] = d[x][y] + 1;
             vis[nx][ny] = true;
             q.push({nx, ny});
         }
     }
 }
}

void solve()
{
 cin >> n >> m;
 for(int i = 1;i <= n; ++ i)
     for(int j = 1;j <= m; ++ j)cin >> mp[i][j];
 
 bfs(1, 1);

 if(!vis[n][m])cout << -1 << '\n';
 else cout << d[n][m] << '\n';
}

int main ()
{
 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 int q = 1;
 while(q--)solve();

 return 0;
}