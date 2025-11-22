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
    int t; cin >> t;
    while(t--){ 
        string s; cin >> s >> k;
        n = s.size();
        for(int i = 1; i <= k; i++) a[i] = i; ok = 1;
        set<string> st;
        while(ok){
            string tmp = "";
            for(int i = 1; i <= k; i++) tmp += s[a[i] - 1];
            st.insert(tmp); sinh();
        }
        for(string x : st) cout << x << endl;
    }
}
