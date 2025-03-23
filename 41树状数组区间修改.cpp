#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 9;

ll a[N], t1[N], t2[N], n;

int lowbit(int x){return x & -x;}

void add(int k, ll x)//向后
{
   for(int i = k;i <= n; i += lowbit(i))
       t1[i] += x, t2[i] += (k - 1) * x;//记录偏移量，不必返回
}

ll getsum(int k)//向前
{
   ll res = 0;
   for(int i = k;i > 0; i -= lowbit(i))
       res += k * t1[i] - t2[i];//返回前缀和，注意偏移量影响t1*k
   return res;
}

int main()
{
   int q;cin >> n >> q;
   for(int i = 1;i <= n; ++ i)cin >> a[i];
   for(int i = 1;i <= n; ++ i)
   {
       add(i, a[i]), add(i + 1, -a[i]);
   }
   while(q --)
   {
       int op;cin >> op;
       if(op == 1)
       {
           ll l, r, v;cin >> l >> r >> v;
           add(l, v), add(r + 1, -v);
       }else{
           ll l, r;cin >> l >> r;
           cout << getsum(r) - getsum(l - 1) << '\n';
       }
   }
}
