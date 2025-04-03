#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
const ll p = 1e6 + 7;

ll dp[N][N], a[N];

int main()
{
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   int n, m;cin >> n >> m;
   for(int i = 1;i <= n; ++ i)cin >> a[i];
   dp[0][0] = 1;
   for(int i = 1;i <= n; ++ i){//种数遍历
   	for(int j = 0;j <= m; ++ j){//前i种有j盆花
   		for(int k = 0;k <= j && k <= a[i]; ++ k){//第i种有k盆花，k不能大于种类的花的数字和当前前i种花摆的数量
   			dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
   		}
   	}
   }
   cout << dp[n][m] << '\n';
   return 0;
}