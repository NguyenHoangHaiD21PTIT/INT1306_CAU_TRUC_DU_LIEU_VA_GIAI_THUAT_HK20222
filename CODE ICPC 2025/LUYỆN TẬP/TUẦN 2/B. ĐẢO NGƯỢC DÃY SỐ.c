#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    if (N % 2 == 1) {
        for (int i = N - 1; i >= 0; i -= 2) printf("%d ", A[i]);
        for (int i = 1; i <= N - 2; i += 2) printf("%d ", A[i]);
    } else {
        for (int i = N - 1; i >= 1; i -= 2) printf("%d ", A[i]);
        for (int i = 0; i <= N - 2; i += 2) printf("%d ", A[i]);
    }
}
