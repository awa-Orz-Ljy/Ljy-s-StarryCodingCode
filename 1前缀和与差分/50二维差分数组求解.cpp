#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 10;
int diff[N][N], a[N][N];
//差分数组客制化，此处的理解是T字但是向右的框框理解，同样左上角右下角的坐标
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
			//此处构建查分数组
			diff[i][j] = a[i - 1][j - 1] + a[i][j] - a[i - 1][j] - a[i][j - 1];
		}
	}
	while (q--) {
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		//此处对差分数组进行客制化
		_solve1(x1, y1, x2, y2, c);
	}
	//此处进行原数组的还原
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] + diff[i][j] - a[i - 1][j - 1];
		}
	}
	//此处输出修改以后的数组
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
