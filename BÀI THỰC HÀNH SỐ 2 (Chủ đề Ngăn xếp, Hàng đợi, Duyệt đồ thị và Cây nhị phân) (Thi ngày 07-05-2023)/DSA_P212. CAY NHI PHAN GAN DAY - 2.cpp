#include<bits/stdc++.h>
using namespace std;
int n, a[10005];
void postOrder(int i) {
    if (i >= n) return; 
    postOrder(2*i + 1); 
    postOrder(2*i + 2); 
    cout << a[i] << " "; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        postOrder(0); 
        cout << endl;
    }
}
