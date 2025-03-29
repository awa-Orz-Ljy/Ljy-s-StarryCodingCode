// StarryCoding P40 【模板】树状数组（单点修改） by 未登录用户
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

ll t[N], n;//树状数组和操作数

int lowbit(int x){return x & -x;}

void add(int k, ll x){//同update
   for(int i = k;i <= n; i += lowbit(i))t[i] += x;
}

ll getsum(int k){//1到k的求和
   ll res = 0;
   for(int i = k;i > 0;i -= lowbit(i))res += t[i];
   return res;
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int q;cin >> n >> q;
   for(int i = 1;i <= n; ++ i){
       int x;cin >> x;
       add(i, x);
   }

   while(q --){
       int op;cin >> op;
       if(op == 1)
       {
           ll k, x;cin >> k >> x;
           add(k, x);
       }else
       {
           ll l, r;cin >> l >> r;
           cout << getsum(r) - getsum(l - 1) << '\n';
       }
   }

   return 0;
}
//没有离散化也行？好好好