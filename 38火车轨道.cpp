#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;

int a[N],pos;
//a[i]描述左边我们希望的顺序排序的列车序列
//而pos是描述右边的车的序号

void solve()
{
	int n;cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];//输入数据
	
	stack<int> stk;//设置空栈
	pos = 1;//右边的第几辆
	for(int i = 1;i<=n;i++)//不是遍历的意思，是我要求第一辆就是1，第二辆就是2，来实现所谓的升序排序
	{
		//pos和n比较是表示右边非空，pos越大代表右边出去的车越多，右边非空就要进入循环
		//中间的栈如果是空的或者栈顶还不符合所需的“1”，就需要进入循环来插入元素
		while(pos<=n && (stk.empty() || stk.top()!=i )) stk.push(a[pos++]);//这里把右边的插入中间即可，自己打表即可知道pos++的含义
		//是为了能够持续插入数据
		if(stk.top()==i)stk.pop();//栈顶满足条件即科送出栈顶元素
		else
		{
			cout<<"No"<<'\n';
			return;
		}
	}
	cout<<"Yes"<<'\n';//循环能够结束说明成功了，输出yes即可
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
	while(_--)solve();
	return 0;
}