#include <bits/stdc++.h>
using namespace std;

int n;
bool check(string &x) {
    int a = 0, b = 0, c = 0;
    for (char ch : x) {
        if (ch == 'A') ++a;
        else if (ch == 'B') ++b;
        else ++c;
    }
    return a && b && c && a <= b && b <= c;
}

void gen() {
    queue<string> q;
    for (char ch = 'A'; ch <= 'C'; ++ch) q.push(string(1, ch));
    vector<string> v;
    while (!q.empty()) {
        string x = q.front(); q.pop();
        if ((int)x.size() == n) continue;
        for (char ch = 'A'; ch <= 'C'; ++ch) {
            string nx = x + ch;
            q.push(nx);
            if ((int)nx.size() >= 3 && check(nx)) v.push_back(nx);
        }
    }
    for (auto &str : v) cout << str << '\n';
}

int main() {
    cin >> n;
    gen();
}
