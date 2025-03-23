#include<bits/stdc++.h>
#define ll  long long
using namespace std;
const int N = 100;
ll a[N][N], pre[N][N];
int main() {
	int n, m, q, x1, y1, x2, y2;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];	//scanf("%d",&a[i][j])
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];//求出了前缀和数组
		}
	}
	while (q--) {//利用前缀和数组进行子矩阵的求和
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << '\n';
		//上面那行代码指：只是减多了加回来，都是在a二维数组上操作，如此实现了子矩阵的求和
	}
	return 0;
}










