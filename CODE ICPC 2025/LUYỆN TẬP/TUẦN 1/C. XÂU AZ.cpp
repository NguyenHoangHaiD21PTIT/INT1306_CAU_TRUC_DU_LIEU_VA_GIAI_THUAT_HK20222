#include <bits/stdc++.h>
using namespace std;
int main() {
    string S; cin >> S;
    int posA = -1, posZ = -1;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == 'A') {
            posA = i;
            break;
        }
    }
    for (int i = S.size() - 1; i >= 0; --i) {
        if (S[i] == 'Z') {
            posZ = i;
            break;
        }
    }
    if (posA != -1 && posZ != -1 && posA <= posZ) cout << (posZ - posA + 1);
    else cout << 0;
}
