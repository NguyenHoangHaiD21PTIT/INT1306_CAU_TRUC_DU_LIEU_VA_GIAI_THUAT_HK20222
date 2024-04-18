#include <bits/stdc++.h>
using namespace std;

int a[10005]; 

void sangnt() {
    for (int i = 0; i < 10005; i++) {
        a[i] = 1;
    }
    a[1] = a[0] = 0;
    for (int i = 2; i * i <= 10005; i++) {
        if (a[i] == 1) {
            for (int j = i * i; j <= 10005; j += i) {
                a[j] = 0;
            }
        }
    }
}

int main() {
    sangnt();
    int t;
    cin >> t;
    while (t--) {
        string s, e;
        cin >> s >> e;
        if (s == e) {
            cout << 0 << endl;
            continue;
        }
        queue<pair<string, int>> q; 
        q.push({s, 0});
        unordered_set<string> visited; 
        visited.insert(s);
        while (!q.empty()) {
            pair<string, int> current = q.front();
            q.pop();
            if (current.first == e) {
                cout << current.second << endl;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                char originalChar = current.first[i];
                for (char c = '0'; c <= '9'; ++c) {
                    current.first[i] = c;
                    if (visited.find(current.first) == visited.end() && a[stoi(current.first)] && stoi(current.first) > 1000) {
                        q.push({current.first, current.second + 1});
                        visited.insert(current.first);
                    }
                }
                current.first[i] = originalChar; // Restore the original character after transformation
            }
        }
    }
    return 0;
}