#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
char s[N];

int main() 
{
    int _; cin >> _;  // 输入测试用例数
    while(_--) 
    {  // 逐个处理每个测试用例
        stack<char> stk;  // 声明栈，用来存储左括号
        cin >> s + 1;  // 输入括号字符串（从索引1开始存储）
        int n = strlen(s + 1);  // 获取字符串长度（从索引1开始）
        bool ans = true;  // 默认括号匹配，初始化为true
        
        // 遍历字符串的每个字符
        for(int i = 1; i <= n && ans; ++i) 
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
            {  // 如果是左括号
                stk.push(s[i]);  // 将左括号入栈
            } 
            else 
            {  // 如果是右括号
                if(stk.empty()) 
                {  // 如果栈为空，表示没有匹配的左括号
                    ans = false;  // 设置结果为不匹配
                    break;  // 退出循环
                }
                // 判断当前右括号是否和栈顶的左括号匹配
                if( (s[i] == ']' && stk.top() == '[') || (s[i] == ')' && stk.top() == '(') ||(s[i] == '}' && stk.top() == '{') )
             	{
                    stk.pop();  // 匹配成功，弹出栈顶元素
                } 
                else 
                {
                    ans = false;  // 不匹配，设置结果为不匹配
                    break;  // 退出循环
                }
            }
        }

        // 如果栈中还有未匹配的左括号，则不匹配
        if(stk.size()) ans = false;
        
        // 输出结果
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;  // 程序正常结束
}
