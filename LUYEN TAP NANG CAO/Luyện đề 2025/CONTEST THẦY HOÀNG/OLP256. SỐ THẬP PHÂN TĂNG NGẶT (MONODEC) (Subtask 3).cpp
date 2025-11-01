#include <bits/stdc++.h>
using namespace std;

vector<int> ds;
void gen() {
    queue<int> q;
    for (int i = 1; i <= 9; i++) q.push(i);
    while (!q.empty()) {
        int num = q.front();
        if (num >= pow(10, 9)) break;
        q.pop();
        ds.push_back(num);
        int last = num % 10; 
        for (int d = last + 1; d <= 9; d++) q.push(num * 10 + d);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ds.push_back(0); gen();
    int t; cin >> t;
    while (t--) {
        int a; cin >> a;
        auto it = upper_bound(ds.begin(), ds.end(), a);
        it--; 
        cout << *it << "\n";
    }
}
