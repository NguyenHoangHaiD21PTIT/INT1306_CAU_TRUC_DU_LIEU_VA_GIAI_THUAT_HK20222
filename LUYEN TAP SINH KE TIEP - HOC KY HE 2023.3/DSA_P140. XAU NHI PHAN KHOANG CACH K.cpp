#include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;

void kt(){
	for(int i = 1; i <= n; i++) a[i] = 0;
}

void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(!i) ok = 0;
	else a[i] = 1;
}

int main(){
    int k; cin >> n >> k;
    kt(); ok = 1;
    int cnt = 0;
    while(ok){
        if(cnt % k == 0){
            for(int i = 1;i <= n; i++) cout << a[i] << " ";
            cout <<endl;
        }
        sinh();
        cnt++;
    }
}
