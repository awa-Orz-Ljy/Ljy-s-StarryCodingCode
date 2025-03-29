#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5;
ll a[N],l[N],r[N];

void solve(){
	int n;cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	
	stack<int> stk;
	for(int i = 1;i <= n;i ++){
		while(!stk.empty()&&a[stk.top()] <= a[i]) stk.pop();
		if(stk.empty()) l[i] = 0;
		else l[i] = stk.top();
		stk.push(i);
	}
	
	while(!stk.empty()) stk.pop();
	
	for(int i = n;i >= 1;i --){
		while(!stk.empty()&&a[stk.top()] < a[i]) stk.pop();//细节
		if(stk.empty()) r[i] = n + 1;
		else r[i] = stk.top();
		stk.push(i);
	}
	ll ans = 0;
	for(int i = 1;i <= n;i ++){
		ans += a[i]*(i - l[i])*(r[i] - i);
	}
	cout<<ans;
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _ = 1;
	while(_ --) solve();	
	return 0;
}