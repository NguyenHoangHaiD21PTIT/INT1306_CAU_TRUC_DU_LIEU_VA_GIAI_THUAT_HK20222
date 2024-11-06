#include <bits/stdc++.h>
using namespace std;

int N, a[30], cnt = 0, ok; 
vector<int> mask;  
vector<string> word; 

void sinh() {
    int i = N - 1;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == -1) ok = 0;
    else a[i] = 1;
}

int get(string word) {
    int mask = 0;
    for (char c : word) mask |= (1 << (c - 'a'));  
    return mask;
}

int main() {
    cin >> N;  
    mask.resize(N); word.resize(N);  
    for (int i = 0; i < N; i++) {
        cin >> word[i];  
        mask[i] = get(word[i]);  
    }
    memset(a, 0, sizeof(a));
    ok = 1;
    while (ok) {
        int sumMask = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == 1) sumMask |= mask[i];
        }
        if (xorMask == (1 << 26) - 1) cnt++;
        sinh();
    }
    cout << cnt;
}
