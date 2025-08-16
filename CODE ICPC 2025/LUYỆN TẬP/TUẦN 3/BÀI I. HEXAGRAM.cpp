#include <bits/stdc++.h>
using namespace std;

bool check1(const vector<int> &a, int A[3], int B[3], int C[5], int s) {
    return a[C[0]] + a[A[0]] + a[B[0]] + a[C[1]] == s &&
           a[C[0]] + a[A[1]] + a[C[2]] + a[C[4]] == s &&
           a[C[1]] + a[B[1]] + a[C[3]] + a[C[4]] == s &&
           a[A[2]] + a[C[2]] + a[C[3]] + a[B[2]] == s;
}

bool check2(const vector<int> &a, int A[3], int B[3], int C[5], int s) {
    return a[A[0]] + a[B[1]] + a[C[1]] + a[C[4]] == s &&
           a[A[2]] + a[C[0]] + a[C[2]] + a[C[4]] == s &&
           a[B[0]] + a[A[1]] + a[C[0]] + a[C[3]] == s &&
           a[B[2]] + a[C[1]] + a[C[2]] + a[C[3]] == s;
}

int main() {
    int T; cin >> T;
    while (T--) {
        vector<int> a(12);

        for (int &x : a) cin >> x;
        int sumAll = accumulate(a.begin(), a.end(), 0);
        if (sumAll % 3 != 0) {
            cout << 0 << "\n";
            continue;
        }
        /*Tổng 12 số là sumAll. Mỗi cạnh có 4 đỉnh và tổng là target, 6 cạnh tổng là 6 * target.
        Nhưng mỗi đỉnh đều nằm trên 2 cạnh, nên tổng của 6 cạnh là 2 * sumAll. --> 6 * target = 2 * sumAll
        --> target = sumAll / 3. Nếu sumAll % 3 != 0
        */
        int target = sumAll / 3;
        vector<array<int,3>> V;
        for (int i = 1; i < 12; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 1; k < j; k++) {
                    if (a[i] + a[j] + a[k] + a[0] == target) V.push_back({k, j, i});
                }
            }
        }
        long long ans = 0;
        int A[3], B[3], C[5];
        int sz = V.size();
        for (int i = 0; i < sz; i++) {
            vector<bool> used(12, false);
            for (int t = 0; t < 3; t++) {
                A[t] = V[i][t];
                used[A[t]] = true;
            }
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int t = 0; t < 3; t++) if (used[V[j][t]]) { ok = false; break; }
                if (!ok) continue;
                vector<bool> used2 = used;
                for (int t = 0; t < 3; t++) {
                    B[t] = V[j][t];
                    used2[B[t]] = true;
                }
                int cnt = 0;
                for (int k = 1; k < 12; k++) if (!used2[k]) C[cnt++] = k;
                sort(A, A+3);
                while (true) {
                    sort(B, B+3);
                    while (true) {
                        sort(C, C+5);
                        while (true) {
                            if (check1(a, A, B, C, target)) ans++;
                            if (check2(a, A, B, C, target)) ans++;
                            if (!next_permutation(C, C+5)) break;
                        }
                        if (!next_permutation(B, B+3)) break;
                    }
                    if (!next_permutation(A, A+3)) break;
                }
            }
        }
        cout << ans << "\n";
    }
}

