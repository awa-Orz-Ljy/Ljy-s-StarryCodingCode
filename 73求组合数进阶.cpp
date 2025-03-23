#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e7+9;
const ll p=1e9+7;
ll fac[N],invfac[N],sum;
ll qmi(ll a,ll b){
   ll res=1;
   while(b){
   	if(b&1)res=res*a%p;
   	a=a*a%p,b>>=1;
   }
   return res;
}
ll inv(ll x){return qmi(x,p-2);
}
ll C(ll n,ll m){
   if(n<0||m<0||n<m)return 0;
   return fac[n]*invfac[n-m]%p*invfac[m]%p;
}
void init(int n){
   fac[0]=1;
   for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
   invfac[n]=inv(fac[n]);
   for(int i=n-1;i>=0;--i)invfac[i]=invfac[i+1]*(i+1)%p;  
}
void solve(){
   ll q,a,b,c,n,m;cin>>q>>a>>b>>c>>n>>m;
   for(int i=1;i<=q;++i){
   sum=(sum+C(n,m))%p;
   n=(n*a%c+b)%c,m=(m*b%c+a)%c;
   }
   cout<<sum<<'\n';
}
int main(){
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   init(1e7);
   int _=1;
   while(_--)
   solve();
   return 0;
}