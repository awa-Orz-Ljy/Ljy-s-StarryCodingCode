//Code Here.
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+9;
ll a[N];

ll stk[N],top;

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;++ i) cin>>a[i];
  ll ans = 0;
  for(int i = 1;i <= n;++ i){
  	int pos = upper_bound(stk + 1,stk + 1 + top,a[i]) - stk;//大于a[i]的元素的位置
  	if(pos == top + 1) top ++;
  	stk[pos] = a[i];//用a[i]来代替，尽可能放更多更大的元素进来，延长长度
  	
  	ans = max(ans,top);
  }
  
  cout<<ans<<'\n';
  return 0;
}