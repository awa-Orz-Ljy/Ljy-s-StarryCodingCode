#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;

ll pre[N], sz[N];

int root(int x)
{
   return pre[x] == x ? x : root(pre[x]);
}

void solve()
{
   int n, m;cin >> n >> m;
   for(int i = 1;i <= n; ++ i)pre[i] = i, sz[i] = 1;
   while(m --)
   {
   	int x, y;cin >> x >> y;
   	int rx = root(x), ry = root(y);
   	if(rx == ry)continue;
   	
   	if(sz[rx] > sz[ry])swap(rx, ry);
   	//sz[rx] <= sz[ry]
   	pre[rx] = ry;
   	sz[ry] += sz[rx];
   }
   vector<int> v;
   for(int i = 1;i <= n; ++ i)
   	if(pre[i] == i)v.push_back(sz[i]);
   sort(v.begin(), v.end());
   for(const auto &i : v)cout << i << ' ';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}