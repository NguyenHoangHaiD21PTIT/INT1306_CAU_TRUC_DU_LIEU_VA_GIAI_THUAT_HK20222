#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a, b;

void postOrder(int i) {
    if (i >= n) return;
    postOrder(2 * i + 1);
    postOrder(2 * i + 2);
    b.push_back(a[i]);
}

long long calc(long long x, long long y, string s) {
    if (s == "+") return x + y;
    else if (s == "-") return y - x;
    else if (s == "*") return x * y;
    else return y / x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        b.clear();

        for (int i = 0; i < n; i++) cin >> a[i];

        postOrder(0);
        
        stack<long long> st;
        for (string x: b) {
            if (x != "+" && x != "-" && x != "*" && x != "/") {
                st.push(stoll(x));
            } else {
                long long x1 = st.top(); st.pop();
                long long x2 = st.top(); st.pop();
                st.push(calc(x1, x2, x));
            }
        }

        cout << st.top() << endl;
    }
}