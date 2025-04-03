#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 9;
const ll p = 998244353;
ll qmi(ll a, ll b)
{
   ll res = 1;
   while (b)
   {
   	if (b & 1) res = res * a % p;
   	a = a * a % p;
   	b >>= 1;
   }
   return res;
}
ll inv(ll x)
{ 
   return qmi(x, p - 2);
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin >> t;
   while (t--)
   {
   	ll a, b, c, q;
   	cin >> a >> b >> c >> q;
   	while (q--)
   	{
   		ll x;
   		cin >> x;
   		cout << (((a * x % p) + b) % p * inv(c * x % p)) % p << '\n';
   	}
   }
   return 0;
}