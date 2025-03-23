#include<bits/stdc++.h>
using namespace std;

void solve(){
	double a,b,h;cin>>a>>b>>h;
	double s = (a + b)*h/2;
	printf("%.2f\n",s);
	return;
}

int main(){
	int T;cin>>T;
	while(T --)solve();
	return 0;
}
