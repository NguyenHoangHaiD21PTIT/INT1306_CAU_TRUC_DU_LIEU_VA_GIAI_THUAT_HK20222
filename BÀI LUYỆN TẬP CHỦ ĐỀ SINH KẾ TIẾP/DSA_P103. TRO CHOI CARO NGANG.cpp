#include <bits/stdc++.h>
using namespace std;

int n; char c;
bool isValid(const string &s) {
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
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n >> c;
		int total = 1 << n;
		for (int mask = 0; mask < total; ++mask) {
			string s;
			for(int i = n-1; i>=0; --i) 
				s += ((mask >> i) & 1) ? 'X' : 'O';
			if(isValid(s)) cout << s << endl;
		}
	}
}
