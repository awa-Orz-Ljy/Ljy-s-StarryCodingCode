#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+10;
ll dp[N],m,n,s,v,w;
int main(){
   //多重背包的二进制优化
   cin>>m>>n;
   for(int i = 1;i <= n;i ++){
       ll x = 1;
       vector<int> arr;
       cin>>s>>w>>v;
       while(s >= x){
           arr.push_back(x);
           s -= x;
           x <<= 1;
       }
       if(s) arr.push_back(s);
       for(auto &k:arr){
           for(int j = m;j >= k*v;j --) dp[j] = max(dp[j],dp[j - k*v] + k*w);
       }
   }
   cout<<dp[m];
   return 0;
}