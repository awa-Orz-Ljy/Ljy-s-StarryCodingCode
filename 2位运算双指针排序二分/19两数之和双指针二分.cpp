#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 2e5 + 5;


int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ans = 0,l = 1, r = n;
        while (l + 1 != r) {
            if (a[r] + a[l] > m){
            	ans += r - l;
            	r --;
            }
            else l ++;//反之
        }
    cout << ans;
    return 0;
}