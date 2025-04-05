#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int s[N];
int a[N];
void _solve1() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];//读n个数，下标从0开始
		s[a[i]] = 0;//初始化各个数字出现的次数，都是0先
	}
	for (int i = 0, j = 0; i < n; i++)//开始遍历a[i]数组，出现的就加1，因为a[i]是可以有相同的数字出现的
	{
		s[a[i]]++;
		while (s[a[i]] > 1) //重复数字一旦出现
		{
			s[a[j]]--;//开始新的遍历，直到该重复数字出现的次数不大于一（等于一）
			j++;
		}
		ans = max(ans, i - j + 1);//计算j到i的距离，这就是最长的连续不重复子序列的长度了，和ans比较以不断更新答案:)
	}
	cout << ans << endl;
}

int main() {
	int T; cin >> T;
	while (T--) _solve1();
	return 0;
}