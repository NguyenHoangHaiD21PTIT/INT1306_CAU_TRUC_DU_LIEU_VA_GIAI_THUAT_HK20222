#include <bits/stdc++.h>
using namespace std;
int main() {
    long long X, Y;
    cin >> X >> Y;
    if (llabs(X - Y) <= 1) cout << "Bob\n";
    else cout << "Alice\n";
}
