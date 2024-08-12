#include <bits/stdc++.h>
using namespace std;
unordered_set<string>db;
bool tKiem(string &cur){
    for (int j = 0; j < cur.size(); ++j) {
        char ori = cur[j];
        for (char c : {'a', 'b', 'c'}) {
            if (c != ori) {
                cur[j] = c;
                if (db.count(cur)) return true;
            }
        }
        cur[j] = ori; // Khôi phục ký tự ban đầu
    }
    return false;
}
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        db.insert(s);
    }
    for (int i = 0; i < M; ++i) {
        string T;
        cin >> T;
        if (tKiem(T)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
