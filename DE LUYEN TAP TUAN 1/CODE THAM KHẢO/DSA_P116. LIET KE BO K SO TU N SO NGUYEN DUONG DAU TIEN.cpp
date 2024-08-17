#include <bits/stdc++.h>
using namespace std;

void in(vector<int> &vt) {
    for(int x : vt) cout << x << " ";
    cout << endl;
}

void Try(int i, int j, int n, int k, vector<int> &vt) {
    if(i > k) {
        in(vt);
        return;
    }
    for(int x = j; x <= n; x++) {
        vt.push_back(x);
        Try(i+1, x, n, k, vt);
        vt.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vt;
    Try(1, 1, n, k, vt);
}



