#include <bits/stdc++.h>
using namespace std;
const int N = 15;
//我们搜索的是n的全排列，注意下面搜索过程的输出配置
int a[N],n;
//标记是否被搜索
bitset<N> vis;

void dfs(int dep)
{
	//此为搜索结束的条件，dep在下面会增加
	if(dep == n + 1)
	{
		for(int i = 1;i <= n; ++ i)cout << a[i] << " \n"[i == n];
		return;
	}
	//搜索
	for(int i = 1;i <= n; ++ i)
	{
		if(vis[i])continue;//遍历过的点就跳过
		//做标记
		vis[i] = true;
		//将i放入当前排列的第dep个位置
		a[dep] = i;
		//继续向下搜索
		dfs(dep + 1);
		//恢复
		a[dep] = 0;
		vis[i] = false;
	}
}

int main()
{
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   cin>>n;//深度
   dfs(1);//从1开始
   return 0;
}