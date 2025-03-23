#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 2e5 + 5;
int a[N];//定义数组

int main() {
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < n; i++) cin >> a[i];//读取数组
    sort(a, a + n);//排序的用法
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {//二分查找，注意:n-1是因为i取n-1的话，就离有边界n太近了qwq
        ll mid, l = i, r = n;
        while (l + 1 != r) {//条件是左右指针相邻
            mid = l + (r - l) / 2;
            if (a[i] + a[mid] <= m) l = mid;//中间值太小，去右边找大的
            else r = mid;//中间值太大，不满足if，去这边找小的
        }
        ans += n - r;//最后用n-r的和来表示答案的对数
    }
    cout << ans;
}