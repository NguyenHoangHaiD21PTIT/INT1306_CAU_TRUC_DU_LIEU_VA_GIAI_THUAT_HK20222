#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000;
int minPrime[MAX + 1] = {};

void era() {
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (!minPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                if (!minPrime[j]) minPrime[j] = i;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (!minPrime[i]) minPrime[i] = i;
    }
}

int countDivisors(int n) {
    int result = 1;
    while (minPrime[n]) {
        int u = minPrime[n];
        int cnt = 0;
        while (n%u==0){
            cnt++;
            n/=u;
        }
        result*=(cnt + 1);
    }
    if (n > 1) result*=2;
    return result;
}

int main() {
    era(); 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(!n){
            cout<<0<<endl;
            continue;
        }
        cout << countDivisors(n) << endl;
    }
    return 0;
}
