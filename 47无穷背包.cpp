#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
using pii = pair<int,int>;
using vecii = vector<vector<int>>;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL),cout.tie(NULL);
   int m,n;//容量和商品数量
   cin>>m>>n;
   vector<int> value(n+1,0),volumetric(n+1,0);
   for(int i = 1;i <= n;i++) cin>>value[i]>>volumetric[i];
   vector<ll> dp(m+1);
   for(int i = 1;i <= n;i++){
   	for(int j = volumetric[i];j <= m;j++){
   		dp[j] = max(dp[j],dp[j-volumetric[i]]+value[i]);
   	}
   }
   cout<<dp[m];
   return 0;
}