#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, D, E, F, cnt = 0;
    cin >> A >> B >> C >> D >> E >> F;
    for (int x11 = 1; x11 < A; x11++){
        for (int x12 = 1; x12 < A; x12++){
            for (int x21 = 1; x21 < B; x21++){            
                for (int x22 = 1; x22 < B; x22++){
                    for (int x31 = 1; x31 < C; x31++){
                        for (int x32 = 1; x32 < C; x32++) {
                            int x13 = A - x11 - x12, x23 = B - x21 - x22, x33 = C - x31 - x32;
                            if (x13 <= 0 || x23 <= 0 || x33 <= 0) continue;
                            if (x11 + x21 + x31 == D && x12 + x22 + x32 == E && x13 + x23 + x33 == F) cnt++;
                        }
                    }
                }
            }
        }
    } 
    cout << cnt;
}
