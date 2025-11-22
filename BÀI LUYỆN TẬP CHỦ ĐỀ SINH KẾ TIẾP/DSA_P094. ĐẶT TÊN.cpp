#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], ok;

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i) i--;
	if(!i) ok = 0;
	else {
		a[i]++;
		for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
	}
}

int main(){
    cin >> n >> k;
    set <string> se;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        se.insert(s);
    }
    vector <string> v(se.begin(), se.end());
    n = v.size(); ok = 1;
    for(int i = 1; i <= k; i++) a[i] = i;
    while (ok) {
        for (int i = 1; i <= k; i++) cout << v[a[i] - 1] << ' ';
        cout << '\n'; sinh();
    }
}
