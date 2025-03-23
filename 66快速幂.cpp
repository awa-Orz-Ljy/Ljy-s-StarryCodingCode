#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c;
ll qmi(ll a,ll b,ll c)
{
   ll res=1;
   while(b)
   {
   	if(b&1)res =res*a%c,b--;
   	a=a*a%c;
   	b>>=1;
   }
   return res;
}
void solve()
{
   cin>>a>>b>>c;
   cout<<qmi(a,b,c)<<'\n';
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   
   	solve();
   }
   return 0;
}