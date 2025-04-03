#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;


int a[109],stk[109],l,r;

//如此排序即可得到想要的子序列长度
//子序列不一定连续捏
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	
	int ans = n;
	for(int i = 1;i <= n;i ++){
		int top = 0;//这里是为i = 2的时候服务的，要重置
		for(int j = 1;j <= i;j ++){
			int pos = lower_bound(stk + 1,stk + top + 1,a[j]) - stk;
			if(pos == top + 1) top ++;
			stk[pos] = a[j];
		}	
		l = i - top;
		top = 0;
		for(int j = i;j <= n;j ++){
			int pos = upper_bound(stk + 1,stk + top + 1,a[j],greater<int>()) - stk;
			if(pos == top + 1) top ++;
			stk[pos] = a[j];
		}	
		r = n - i + 1 - top;
		ans = min(ans,l + r);
	}
	cout<<ans;
	return 0;
}