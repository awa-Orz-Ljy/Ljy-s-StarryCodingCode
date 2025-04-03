#include<bits/stdc++.h>
using namespace std;
using ll= long long;
ll dp[1001][1001];//在前 i 个物品中选择，背包容量为 j 时所能获得的最大价值
ll t[101],v[101];//时间和价值
ll T,M;//最大时间，最大数量
void solve(){
   for(int i=1;i<=M;i++)//数量，输入时间和价值
       cin>>t[i]>>v[i];
       
   for(int i=1;i<=M;i++){//在i数量，j时间内得到的dp价值
       for(int j=0;j<=T;j++){
           if(j>=t[i])//时间不能花费完了
        		dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);//没选就是原来的样子，选了就是耗尽时间加价值
           else 
           		dp[i][j]=dp[i-1][j];
       }
   }
   cout<<dp[M][T]<<'\n';
   
}
int main(){
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   while(cin>>T>>M){
       if(T==0&&M==0) break;
       solve();
   }
   return 0;
}