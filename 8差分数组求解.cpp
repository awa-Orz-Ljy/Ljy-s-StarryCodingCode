#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5 + 10;
ll a[N], diff[N], pre[N];
void _solve2()
{
	int n, p, q;//n长度的数组，p次区间加，q次区间求和；
	cin >> n >> p >> q;
	for (int i=1; i <= n; i++) {//输入数组
		cin >> a[i];
	}
	for (int i=1; i <= n; i++) {//构建差分数组
		diff[i] = a[i] - a[i - 1];
	}
	while (p--) {//开始加数操作
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}
	for (int i=1; i <= n; i++) {//还原数组，
		a[i] = a[i - 1] + diff[i];
	}
	for (int i=1; i <= n; i++) {//构建前缀和数组以求区间和
		pre[i] = pre[i - 1] + a[i];
	}
	while (q--) {//前缀和数组求和过程
		int l, r;
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	_solve2();
	return 0;
}
