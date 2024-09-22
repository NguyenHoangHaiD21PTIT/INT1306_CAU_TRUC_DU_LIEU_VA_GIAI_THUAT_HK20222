#include<bits/stdc++.h>
using namespace std;

long long calc(vector<int>& A, vector<int>& op, int M) {
    long long res = A[0] % M;  
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == 0) res = (res + A[i + 1]) % M;   
        else if (op[i] == 1) res = (res - A[i + 1] + M) % M; 
        else if (op[i] == 2) res = (res * A[i + 1]) % M; 
    }
    return res;
}

void sinh(vector<int>& op, int& ok) {
    int i = op.size() - 1;
    while (i >= 0 && op[i] == 2) i--; 
    if (i == -1) ok = 0; 
    else {
        op[i]++; 
        for (int j = i + 1; j < op.size(); j++) op[j] = 0; 
    }
}

int main() {
    int T; 
    cin >> T; 
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N); 
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<int> op(N - 1, 0); 
        int ok = 1, cnt = 0;
        while (ok) {
            long long tmp = calc(A, op, M);
            if (tmp==0) cnt++; 
            sinh(op, ok); 
        }
        cout << cnt << endl; 
    }
    return 0;
}