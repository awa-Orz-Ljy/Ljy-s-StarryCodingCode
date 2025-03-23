#include<bits/stdc++.h>
using namespace std;
using ll= long long;
ll dp[1001][1001];
ll v[101],t[101];
ll T,M;
void solve(){
   for(int i=1;i<=M;i++)
       cin>>t[i]>>v[i];
   for(int i=1;i<=M;i++){
       for(int j=0;j<=T;j++){
           if(j>=t[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
           else dp[i][j]=dp[i-1][j];
       }

   }
   cout<<dp[M][T]<<'\n';



}
int main(){
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   while(cin>>T>>M){
       if(T==0&&M==0)
           break;
       solve();
   }
   return 0;


}