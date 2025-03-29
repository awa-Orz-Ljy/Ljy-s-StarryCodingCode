#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
ll a[N], l[N], r[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    stack<int> stk;

    // 先求 l[] < a[i]
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && a[stk.top()] >= a[i])
            stk.pop();
        // 此时栈顶就是 l[i]
        if (stk.empty())
            l[i] = 0;  // 区间之外的数字
        else
            l[i] = stk.top();

        stk.push(i);  // 把 i 入栈
    }

    // 清空栈
    while (!stk.empty()) {
        stk.pop();
    }

    // 再求 r[] <= a[i], 因为遇到相等的数字的时候要分配给右边的数字
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() && a[stk.top()] > a[i])
            stk.pop();
        // 此时栈顶就是 r[i]
        if (stk.empty())
            r[i] = n + 1;  // 区间之外的数字
        else
            r[i] = stk.top();

        stk.push(i);  // 把 i 入栈
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i] * (r[i] - i) * (i - l[i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}    