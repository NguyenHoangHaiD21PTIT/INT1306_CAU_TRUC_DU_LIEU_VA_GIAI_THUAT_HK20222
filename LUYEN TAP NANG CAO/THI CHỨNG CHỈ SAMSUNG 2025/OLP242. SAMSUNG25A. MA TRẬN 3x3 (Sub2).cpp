#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, D, E, F, cnt = 0;
    cin >> A >> B >> C >> D >> E >> F;
    for (int X11 = 1; X11 < A; X11++) {
        for (int X12 = 1; X12 < A; X12++) {
            for (int X21 = 1; X21 < B; X21++) {
                for (int X22 = 1; X22 < B; X22++) {
                    int X13 = A - X11 - X12, X23 = B - X21 - X22, X31 = D - X11 - X21;
                    int X32 = E - X12 - X22, X33a = C - X31 - X32, X33b = F - X13 - X23;
                    if (X13 <= 0 || X23 <= 0 || X31 <= 0 || X32 <= 0 || X33a <= 0) continue;
                    if (X33a == X33b) cnt++;
                }
            }
        }
    }
    cout << cnt;
}
