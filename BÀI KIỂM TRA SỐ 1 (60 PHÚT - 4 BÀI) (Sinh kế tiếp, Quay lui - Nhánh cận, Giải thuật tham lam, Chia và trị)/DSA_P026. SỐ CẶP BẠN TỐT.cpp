#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, k, A[25], B[60005], i;
    long long S = 0;
    char x[30];

    scanf("%ld %ld", &n, &k);

    for (i = 1; i <= n; i++) {
        scanf("%s", x);
        B[i] = strlen(x);
    }

    for (i = n + k; i > n; i--) {
        B[i] = 0;
    }

    for (i = 2; i <= 20; i++) {
        A[i] = 0;
    }

    if (k < n) {
        for (i = k; i >= 1; i--) {
            A[B[i]]++;
        }
    } else {
        for (i = n; i >= 1; i--) {
            A[B[i]]++;
        }
    }
    
    for (i = 1; i <= n; i++) {
        A[B[i + k]]++;
        S += A[B[i]] - 1;
        A[B[i]]--;
    }

    // In ra tổng số cặp bạn tốt
    printf("%lld", S);

    return 0;
}
