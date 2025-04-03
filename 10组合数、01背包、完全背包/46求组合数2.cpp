#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 7;
const int p = 1e9 + 7;

ll fac[N];

void init(){//阶乘初始化
   fac[0] = 1;
   for (ll i = 1; i <= 1e7; i++)fac[i] = i * fac[i - 1] % p;
}

ll qmi(ll a, ll b)//快速幂
{
   ll ans = 1;
   while (b)
   {
   	if (b & 1)ans = ans * a % p;
   	a = a * a % p;
   	b >>= 1;
   }
   return ans;
}

ll inv(ll x)//求逆元
{
   return qmi(x, p - 2) % p;
}

void solve()
{
   ll n, m; cin >> n >> m;
   
   cout << (fac[n] % p) * inv(fac[m] * fac[n - m] % p) % p << '\n';
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   init();
   int _; cin >> _;
   while (_--)solve();
   return 0;
}