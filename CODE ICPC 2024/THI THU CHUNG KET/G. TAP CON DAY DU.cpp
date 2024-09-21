#include <bits/stdc++.h>
using namespace std;

int N, res = 0;  
vector<int> bitmask;  // Lưu bitmask của từng từ

int get(string word) {
    int mask = 0;
    for (char c : word) mask |= (1 << (c - 'a'));  // Bật bit tương ứng với ký tự c
    return mask;
}

void Try(int idx, int curMask) {
    if (idx == N) {
        if (curMask == (1 << 26) - 1) res++;
        return;
    }
    Try(idx + 1, curMask);
    Try(idx + 1, curMask | bitmask[idx]);
}

int main() {
    cin >> N;
    bitmask.resize(N);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bitmask[i] = get(word);  
    }
    Try(0, 0);
    cout << res << endl;
}
