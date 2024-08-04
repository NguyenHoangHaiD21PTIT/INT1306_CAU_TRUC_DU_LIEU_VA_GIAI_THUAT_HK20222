#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string check = "No";
    for (int y = 0; y * 7 <= N; y++) {
        int res = N - y * 7;
        if (res % 4 == 0) {
            check = "Yes";
            break;
        }
    }
    cout<<check;
}
