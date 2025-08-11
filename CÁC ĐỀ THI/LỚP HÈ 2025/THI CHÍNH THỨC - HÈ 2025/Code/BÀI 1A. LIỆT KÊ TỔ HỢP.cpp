#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], ok, b[100];

void kt(){
	for(int i = 1; i <= k; i++) a[i] = i;
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i) i--;
	if(i == 0) ok = 0;
	else {
		a[i]++;
		for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
	}
}

int main(){
	int m; cin >> n >> k >> m;
    kt(); ok = 1;
    while(ok){
        int check = 0;
        for (int i = 1; i <= k; i++){
            if(a[i] == m) {
                check = 1;
                break;
            }
        }
        if(check) {
            for(int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
        sinh();
    }
}
