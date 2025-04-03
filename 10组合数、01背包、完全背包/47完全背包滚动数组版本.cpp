#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505, M = 1e5 + 9;
ll dp[M];

int main(){
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   ll m, n;cin >> m >> n;
   for(int i = 1;i <= n; ++ i){
   		ll w, v;cin >> w >> v;
   		for(int j = v;j <= m; ++ j){
   			dp[j] = max(dp[j], dp[j - v] + w);
   		}
   }
   cout << dp[m] << '\n';
   return 0;
}