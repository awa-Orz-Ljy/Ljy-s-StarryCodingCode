#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

void solve() {
  ll n; cin >> n;
  vector<ll> ans;
  for(ll i = 2; i <= n / i; i++) {//从sqrt(n)的左边开始找
  	if(n % i != 0) continue;
  	ans.push_back(i);
  	while(n % i == 0) n /= i;//把n里面的i除掉，要用到额外循环
  }
  ans.push_back(n);
  for(auto &num : ans) cout << num << ' ';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}