#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 9;

bitset<N> vis;
void solve()
{
   int n; cin >> n;
   
   vis[0] = vis[1] = true;
   for (ll i = 2; i <= n; ++i)
   	if (!vis[i])for (ll j = i * i; j <= n; j += i)vis[j] = true;
   
   for (int i = 1; i <= n; ++i)if (!vis[i])cout << i << ' ';
}


int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();
   return 0;
}