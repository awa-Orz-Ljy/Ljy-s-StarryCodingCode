#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int INF = 2e9 + 1;
int n,a[N],q,x,y;
ll l[N],r[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	a[0] = -INF,a[n + 1] = INF;
	
	for(int i = 1;i < n;i ++){
		int min_ = min(a[i + 1] - a[i],a[i] - a[i - 1]);
		if(min_ == a[i + 1] - a[i]) l[i] = 1;//最近的店，左往右
		else l[i] = a[i + 1] - a[i];
	}	
	
	for(int i = n;i > 1;i --){
		int min_ = min(a[i + 1] - a[i],a[i] - a[i - 1]);
		if(min_ == a[i] - a[i - 1]) r[i] = 1;//最近的店,右往左
		else r[i] = a[i] - a[i - 1];	
	}	
	//前缀和构建
	for(int i = 1;i <= n;i ++){
		l[i] += l[i - 1];
		r[i] += r[i - 1];
	}
	
	cin>>q;
	while(q --){
		cin>>x>>y;
		if(x < y) cout<<l[y - 1] - l[x - 1]<<'\n';
		else cout<<r[x] - r[y]<<'\n';
	}
	return 0;
}