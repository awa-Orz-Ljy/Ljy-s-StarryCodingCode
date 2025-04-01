#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;

ll pre[N],cnt[N];//桶的思想来记录以i为根的节点的个数

int root(int x){return pre[x] = (pre[x] == x ? x : root(pre[x]));}//pre伸出一只手去抓节点，不是的话就继续找

void merge(int x,int y){pre[root(x)] = root(y);}//连接两个点（也可以连接两个联通块）

bool iscon(int x,int y){return root(x) == root(y);}

void solve(){
	int n,m;cin>>n>>m;
	for(int i = 1;i <= n;i ++)pre[i] = i;//初始化
	for(int i = 1;i <= m;i ++){
		int u,v;cin>>u>>v;
		merge(u,v);
	}
	for(int i = 1;i <= n;i ++) cnt[root(i)] ++;//记录的是每个根有多少个节点，即联通块的大小
	vector<int> v;
	for(int i = 1;i <= n;i ++){
		if(cnt[i]) v.push_back(cnt[i]);//把存在节点的联通块的大小存入v
	}
	sort(begin(v),end(v));
	for(auto &i : v)cout<<i<<' ';
}
int main(){
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   while(t --)solve();
   return 0;
}