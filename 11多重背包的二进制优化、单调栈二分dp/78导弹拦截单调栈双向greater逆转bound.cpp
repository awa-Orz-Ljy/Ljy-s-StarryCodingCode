#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
const ll p = 1e9 + 7;

ll a[N],stk[N];
//很有意思，最长不上升和最长上升，
//greater把upper的大于等于取反变成了小于
//lower即是严格大于
//如此排序即可得到想要的子序列长度
//子序列不一定连续捏
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 1;
	while(cin>>a[n]) n ++;
	n --;
	
	int top = 0,ans = 0;
	
	for(int i = 1;i <= n;i ++){
		int pos = upper_bound(stk + 1,stk + top + 1,a[i],greater<int>()) - stk;
		if(pos == top + 1) top ++;
		stk[pos] = a[i];
		ans = max(ans,top);
	}	
	cout<<ans<<'\n';
	
	top = 0,ans = 0;
	
	for(int i = 1;i <= n;i ++){
		int pos = lower_bound(stk + 1,stk + top + 1,a[i]) - stk;
		if(pos == top + 1) top ++;
		stk[pos] = a[i];
		ans = max(ans,top);
	}
	cout<<ans<<'\n';
	
	return 0;
}