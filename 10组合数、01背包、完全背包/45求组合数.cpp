#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
const int p = 1e9 + 7;

int n, m, q;
ll dp[N][N];


void solve()
{
   int n, m; cin >> n >> m;
	//初始化
   for (int i = 0; i < n; ++i)dp[i][0] = 1;
	//要选择j个，未选择i则要在i-1里面选j个，选了i则要在i-1里面选择j-1个
   for (int i = 1; i < n; ++i)
   	for (int j = 1; j <= i; ++j)//i个物品选j个
   		dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % p;

   for (int i = 0; i < n; ++i)
   	for (int j = 0; j < m; ++j)
   		cout << dp[i][j] << " \n"[j == m - 1];//当j == m - 1输入回车

}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();
   return 0;
}