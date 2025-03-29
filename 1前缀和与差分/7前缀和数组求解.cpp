#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll pre[N], a[N];
void _solve1() {
    int n,q,l,r;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    //进行求和
    while (q--) 
    {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
}
int main()
{
    int T; cin >> T;
    while (T--) _solve1();
    return 0;
}