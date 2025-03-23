#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a,ll b)
{
   return b==0 ? a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}
void solve()
{
   ll a ,b;
   cin>>a>>b;
   cout<<gcd(a,b)<<" "<<lcm(a,b)<<'\n';
   
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