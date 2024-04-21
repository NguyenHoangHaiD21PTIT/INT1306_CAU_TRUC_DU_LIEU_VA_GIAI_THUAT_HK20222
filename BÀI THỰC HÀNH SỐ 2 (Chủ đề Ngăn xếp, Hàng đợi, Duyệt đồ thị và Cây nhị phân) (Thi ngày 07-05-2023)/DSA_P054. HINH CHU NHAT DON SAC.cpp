#include<bits/stdc++.h>
using namespace std;

long long kq(long long a[], long long n){
    long long l[n], r[n];
    // Tìm Vị trí phần tử đầu tiên bên trái, bên phải a[i] bé hơn a[i]
    //l, r là cận trái, phải của HCN
    for(long long i = 0;i<n;i++) cin>>a[i];
    stack<long long>st1, st2;
    for(long long i = n - 1;i>=0;i--){
        while(!st1.empty() && a[i] <= a[st1.top()]) st1.pop();
        if(st1.empty()) r[i] = n - 1;
        else r[i] = st1.top() - 1;
        st1.push(i);
    }
    for(long long i = 0;i<n;i++){
        while(!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
        if(st2.empty()) l[i] = 0;
        else l[i] = st2.top() + 1;
        st2.push(i);
    }
    long long res = -1;
    for(long long i = 0;i<n;i++){
        res = max(res, 1LL * (r[i] - l[i] + 1) * a[i]);
    }
    return res;
}

int main(){
	long long m, n;
	cin>>m>>n;
	long long a[n], b[n];
	for(int i = 0;i<n;i++) cin>>a[i], b[i] = m - a[i];
	long long res = -1;
	res = max(res, kq(a, n));
	res = max(res, kq(b, n));
	cout<<res<<endl;
}
