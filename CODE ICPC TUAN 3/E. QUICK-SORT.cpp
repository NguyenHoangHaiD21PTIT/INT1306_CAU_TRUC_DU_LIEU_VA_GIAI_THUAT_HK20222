#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], l[n], r[n];
    stack<int> st1; stack<int> st2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (!st1.empty() && a[i] >= a[st1.top()]) st1.pop();
        if (st1.empty()) l[i] = -1;
        else l[i] = st1.top();
        st1.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st2.empty() && a[i] < a[st2.top()]) st2.pop();
        if (st2.empty()) r[i] = -1;
        else r[i] = st2.top();
        st2.push(i);
    }
    vector<int>res;
    for (int i = 0; i < n; i++) {
        if (l[i] == -1 && r[i] == -1) res.push_back(a[i]);
    }
    cout<<res.size()<<" ";
    int x = res.size();
    int y = min(100, x);
    for(int i = 0;i<y;i++) cout<<res[i]<<" ";
}
