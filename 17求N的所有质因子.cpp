#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

void solve() {
  ll n; cin >> n;
  vector<ll> ans;
  for(ll i = 2; i <= n / i; i++) {
  	if(n % i) continue;
  	ans.push_back(i);
  	while(n % i == 0) n /= i;
  }
  ans.push_back(n);
  for(int num : ans) {
  	cout << num << ' ';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}