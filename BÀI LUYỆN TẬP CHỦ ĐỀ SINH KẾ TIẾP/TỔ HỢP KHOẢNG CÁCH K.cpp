#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok;

void kt(){
	for(int i = 1; i <= k; i++) a[i] = i;
}

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
	cin >> n >> k; kt(); ok = 1;
    int cnt = 0;
    while(ok){
        if(cnt % k == 0){
            for(int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
        sinh();
        cnt++;
    }
}
