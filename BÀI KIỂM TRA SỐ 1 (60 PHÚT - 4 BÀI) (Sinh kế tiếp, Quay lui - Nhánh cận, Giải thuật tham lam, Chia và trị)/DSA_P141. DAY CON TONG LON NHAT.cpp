#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, u, v;
    cin>>n>>u>>v;
    vector<int>a(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
    deque<int> dq;
    int mx = INT_MIN;
    for (int i = u; i <= n; ++i) {
        if (!dq.empty() && dq.front() < i - v) dq.pop_front();
        if (!dq.empty()) mx = max(mx, p[i] - p[dq.front()]);
        while (!dq.empty() && p[dq.back()] >= p[i - u + 1]) dq.pop_back();
        dq.push_back(i - u + 1);
    }
    cout<<mx;
}
/*
Cho mảng A có N phần tử và 2 số u, v. Xác định tổng lớn nhất của dãy con liên tiếp có độ dài
trong đoạn [u, v] */
