#include<bits/stdc++.h>
#define ll  long long
using namespace std;
const int N = 100;
ll a[N][N], pre[N][N];
int main() {
	int n, m, q, x1, y1, x2, y2;//左上角右下角的坐标
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];	//scanf("%d",&a[i][j])
			//构建前缀和，J字形状的框框理解，-1是抽象理解
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];
		}
	}
	//求和，子矩阵的和
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}










