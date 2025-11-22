#include<bits/stdc++.h>
using namespace std;
//O: 0, X: 1
string s = ""; int n, ok;

void sinh(){
	int i = n - 1;
	while(i >=0 && s[i] == 'X'){
		s[i] = 'O';
		i--;
	}
	if(i == -1) ok = 0;
	else s[i] = 'X';
}

bool check(string s, char c){
    int maxX = 0, maxO = 0, cntX = 0, cntO = 0;
    for (char ch : s) {
        if(ch == 'X') {
            cntX++;
            maxX = max(maxX, cntX);
            cntO = 0;
        } else {
            cntO++;
            maxO = max(maxO, cntO);
            cntX = 0;
        }
    }
    if(c == 'X') return maxX > maxO && maxX >= 5;
    else return maxO > maxX && maxO >= 5;
}

int main(){
	int t; cin >> t;
	while(t--){
		char c; cin >> n >> c; 
        s = string (n, 'O'); ok = 1;
		while (ok){
            if (check(s, c)) cout << s << endl;
            sinh();
        }
	}
}
