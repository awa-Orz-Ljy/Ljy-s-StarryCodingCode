#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 10;
int diff[N][N], a[N][N];

void _solve1(int x1, int y1, int x2, int y2, int c) {
	diff[x1][y1] += c;
	diff[x2 + 1][y1] -= c;
	diff[x1][y2 + 1] -= c;
	diff[x2 + 1][y2 + 1] += c;
}
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			diff[i][j] = a[i - 1][j - 1] + a[i][j] - a[i - 1][j] - a[i][j - 1];
		}
	}
	while (q--) {
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		_solve1(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] + diff[i][j] - a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}


//pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];//求出了前缀和数组
//pre[x2][y2] = pre[x2 - 1][y2] + pre[x2][y2 - 1] + a[x2][y2] - pre[x1 - 1][y1 - 1];
//a[x2][y2] = a[x2 - 1][y2] + a[x2][y2 - 1] + diff[x2][y2] - a[x1 - 1][y1 - 1];