#include <bits/stdc++.h>
using namespace std;
long long f[92] = {};
void fibo() {
	f[1] = 1;
	f[2] = 1;
	for(long long i=3; i <= 93; i++) {
		f[i] = f[i-1] + f[i-2];
	}
}
int main() {
	int t;
	cin >> t;
	fibo();
	while(t--) {
        int a, b; cin >> a >> b;
        for(int i = a; i<=b; i++) {
            cout << f[i] << " ";
        }	
		cout<<endl;
	}	
}