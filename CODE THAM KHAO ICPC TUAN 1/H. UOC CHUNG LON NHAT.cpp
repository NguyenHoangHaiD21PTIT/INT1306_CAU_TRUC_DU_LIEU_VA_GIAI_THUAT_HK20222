#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1000000 + 5;
int countX[MAX_A];

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        memset(countX, 0, sizeof(countX));
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            countX[num]++;
        }
        int max_gcd = 0;
        for (int i = 1; i < MAX_A; ++i) {
            int num_countX = 0;
            for (int j = i; j < MAX_A; j += i) {
                num_countX += countX[j];
                if (num_countX >= 2) {
                    max_gcd = i;
                    break;
                }
            }
        }

        cout << max_gcd << "\n";
    }

    return 0;
}
