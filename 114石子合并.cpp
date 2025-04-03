#include <bits/stdc++.h>
using namespace std;

const int N = 305;
using ll = long long;

ll a[N], prefix[N], dp[N][N];

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;cin >> n;
   for(int i = 1;i <= n; ++ i)cin >> a[i];
   for(int i = 1;i <= n; ++ i)prefix[i] = prefix[i - 1] + a[i];
   for(int i = 1;i <= n; ++ i)dp[i][i] = 0;
   for(int len = 2;len <= n; ++ len)
   {
       for(int i = 1;i + len - 1 <= n; ++ i)
       {
           int j = i + len - 1;
           ll sum = prefix[j] - prefix[i - 1];
           dp[i][j] = dp[i][i] + dp[i + 1][j] + sum;
           // k = i的情况已经考虑过了
           for(int k = i + 1;k < j; ++ k)
           {
               dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
           }
       }
   }

   cout << dp[1][n] << '\n';
   return 0;
}