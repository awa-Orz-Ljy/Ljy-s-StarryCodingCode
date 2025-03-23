#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

//升序排序并且去重！！！
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	set<int> st;
	int n;cin>>n;
	for(int i=0;i<=n;i++)
	{
		int x;cin>>x;
		st.insert(x);//创建这个向量
		
	}
	for(auto &val : st)cout<< val<<' ';//引用，auto是遍历的st里面的东西
	return 0;
}