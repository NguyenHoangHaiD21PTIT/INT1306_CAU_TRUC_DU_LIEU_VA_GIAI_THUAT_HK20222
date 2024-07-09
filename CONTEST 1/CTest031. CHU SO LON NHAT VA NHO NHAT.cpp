#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        string N;
        cin >> N;  
        char max_digit = '0';
        char min_digit = '9';
        for (char digit : N) {
            if (digit > max_digit) max_digit = digit;
            if (digit < min_digit) min_digit = digit;
        }
        cout << max_digit << " " << min_digit << endl;
    }
}
