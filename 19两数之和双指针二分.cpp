#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 2e5 + 5;
int a[N];//��������

int main() {
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < n; i++) cin >> a[i];//��ȡ����
    sort(a, a + n);//������÷�
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {//���ֲ��ң�ע��:n-1����Ϊiȡn-1�Ļ��������б߽�n̫����qwq
        ll mid, l = i, r = n;
        while (l + 1 != r) {//����������ָ������
            mid = l + (r - l) / 2;
            if (a[i] + a[mid] <= m) l = mid;//�м�ֵ̫С��ȥ�ұ��Ҵ��
            else r = mid;//�м�ֵ̫�󣬲�����if��ȥ�����С��
        }
        ans += n - r;//�����n-r�ĺ�����ʾ�𰸵Ķ���
    }
    cout << ans;
}