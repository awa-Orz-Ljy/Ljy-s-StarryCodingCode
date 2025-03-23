#include <bits/stdc++.h>
using namespace std;
const int N = 15;

int a[N],n;

bitset<N> vis;//bool数组

void dfs(int dep)
{
	if(dep == n + 1)
	{
		for(int i = 1;i <= n; ++ i)cout << a[i] << " \n"[i == n];
		return;
	}
	for(int i = 1;i <= n; ++ i)
	{
		if(vis[i])continue;
		
		vis[i] = true;
		a[dep] = i;
		
		dfs(dep + 1);
		
		//恢复现场
		a[dep] = 0;
		vis[i] = false;
		
	}
}

int main()
{
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   
   cin>>n;
   dfs(1);
  
   return 0;
}