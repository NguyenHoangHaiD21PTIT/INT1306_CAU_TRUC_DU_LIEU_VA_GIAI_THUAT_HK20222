#include <bits/stdc++.h>
using namespace std;
int freq[1000006];
int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    sort(A, A + N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool valid = true;
        freq[A[i]]--;
        // Kiểm tra tất cả các ước của A[i]
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                if (freq[j] || freq[A[i]/j]){
                    valid = false;
                    break;
                }
            }
        }
        if (valid) cnt++;
        freq[A[i]]++;
    }
    cout << cnt << endl;
}

