#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;  // 定义数组最大长度，3e5是为了容纳大约30万个元素
int a[N], prefix[N];  // a存储原数组，prefix数组用于区间和的前缀和（未使用）

vector<int> X;  // 用来存储所有关键的离散化的值

// 定义结构体Q1和Q2来存储问题中的查询和操作
struct Q1{
   int x, y;
} q1[N], q2[N];//操作和询问

int t[N], m;  // 树状数组t，m为离散化后数组X的大小

// 查找x在离散化数组X中的位置，返回[1, X.size()]的索引
int bin(int x) {
   return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

// 返回x的最低位1的值
int lowbit(int x) {
    return x & -x;
}

// 更新树状数组，给位置k增加x的值
void update(int k, int x) {
    for (int i = k; i <= m; i += lowbit(i)) {
        t[i] += x;
    }
}

// 求区间[1, k]的和
int getsum(int k) {
    int res = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
        res += t[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // 优化输入输出
    int n, q;
    cin >> n >> q;  // 读取n次操作和查询次数q
    
    // 1. 离线存下所有关键点，保存操作中的坐标信息
    for (int i = 1; i <= n; ++i) {//开始读取
        cin >> q1[i].x >> q1[i].y;
        X.push_back(q1[i].x);  // 存储每个操作的x坐标
    }
    for (int i = 1; i <= q; ++i) {//开始查询
        cin >> q2[i].x >> q2[i].y;
        X.push_back(q2[i].x);  // 存储查询的左边界
        X.push_back(q2[i].y);  // 存储查询的右边界
    }
    
    // 2. 排序并去重离散化数组X
    sort(X.begin(), X.end());  // 排序所有的关键点
    X.erase(unique(X.begin(), X.end()), X.end());  // 去除重复的元素

    // 变成了一个简单的树状数组问题
    m = X.size();  // 离散化后的元素个数

    // 3. 用离散化的索引来更新树状数组，重要
    for (int i = 1; i <= n; ++i) {
        int k = bin(q1[i].x);  // 离散化后的索引
        int x = q1[i].y;       // 对应的值
        update(k, x);  // 更新树状数组
    }
    
    // 4. 处理所有查询，使用树状数组查询区间和
    for (int i = 1; i <= q; ++i) {
        int l = bin(q2[i].x);  // 离散化后的左边界
        int r = bin(q2[i].y);  // 离散化后的右边界
        cout << getsum(r) - getsum(l - 1) << '\n';  // 输出区间和
    }
    return 0;
}
//四个函数，主要就是update和getsum，其中要用到的工具就是bin（二分返回索引）和lowbit（循环中寻找父节点的关键长度）
//且需要有个可变vector和存储操作和查询的结构体q1，q2





















