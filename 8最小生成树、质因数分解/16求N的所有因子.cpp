// StarryCoding P16 【模板】求N的所有因子 by eriktse
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

void solve(){
   ll n; cin >> n;
   vector<ll> v;
   for(int i = 1; i <= sqrt(n) ; i++)
   {
   	if(n % i != 0) continue;//i不是因子
   	v.push_back(i);
   	if(i != n/i) v.push_back(n/i); //防止因子重复因为i和n/i都是因子
   }
   sort(v.begin(), v.end());
   for(auto &i : v) cout << i << ' ';
}	

int main()
{
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int _ = 1; 
   while(_ --) solve();
   return 0;
}