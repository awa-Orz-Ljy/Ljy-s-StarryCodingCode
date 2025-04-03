#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
ll n,m,dp[N],w,s,v;
int main(){
   //多重背包与完全背包的区别：每个物品的数目都有限制
   //此做法将每个数目的商品都跑一遍，做法等同于01背包
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   cin>>m>>n;
   for(int i=1;i<=n;i++){
       cin>>s>>w>>v;
       while(s--){//s次01背包
           for(int j=m;j>=v;j--)dp[j]=max(dp[j],dp[j-v]+w);
       }
   }
   cout<<dp[m]<<'\n';
   return 0;
}