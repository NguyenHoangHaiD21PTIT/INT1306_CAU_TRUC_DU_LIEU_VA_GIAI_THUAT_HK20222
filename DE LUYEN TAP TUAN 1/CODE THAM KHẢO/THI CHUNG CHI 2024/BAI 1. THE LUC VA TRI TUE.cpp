#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll a, b, c, d; 
    cin >> a >> b >> c >> d;
    if (c > d) swap(c, d);
    ll chan = ((b - a) / 2 + 1) * (a + b) / 2;  
    ll le   = ((d - c) / 2 + 1) * (c + d) / 2;  
    cout << 2 * llabs(chan - le);
}
