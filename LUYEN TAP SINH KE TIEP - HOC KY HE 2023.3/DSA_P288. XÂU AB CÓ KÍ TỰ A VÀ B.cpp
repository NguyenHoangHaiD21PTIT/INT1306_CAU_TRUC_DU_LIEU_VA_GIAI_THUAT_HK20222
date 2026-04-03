#include<bits/stdc++.h>
using namespace std;

string s = ""; int n, ok;

void sinh(){
	int i = n - 1;
	while(i >=0 && s[i] == 'B'){
		s[i] = 'A';
		i--;
	}
	if(i == -1) ok = 0;
	else s[i] = 'B';
}

int main(){
    cin >> n; s = string (n, 'A'); ok = 1;
    int cnt = 1;
    while(ok){
        if(cnt!=1 && cnt != pow(2, n)) cout << s << endl;
        cnt++; sinh();
    }
}
