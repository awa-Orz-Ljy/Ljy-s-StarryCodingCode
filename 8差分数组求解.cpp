#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5 + 10;
ll a[N], diff[N], pre[N];
void _solve2()
{
	int n, p, q;//n���ȵ����飬p������ӣ�q��������ͣ�
	cin >> n >> p >> q;
	for (int i=1; i <= n; i++) {//��������
		cin >> a[i];
	}
	for (int i=1; i <= n; i++) {//�����������
		diff[i] = a[i] - a[i - 1];
	}
	while (p--) {//��ʼ��������
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}
	for (int i=1; i <= n; i++) {//��ԭ���飬
		a[i] = a[i - 1] + diff[i];
	}
	for (int i=1; i <= n; i++) {//����ǰ׺���������������
		pre[i] = pre[i - 1] + a[i];
	}
	while (q--) {//ǰ׺��������͹���
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
