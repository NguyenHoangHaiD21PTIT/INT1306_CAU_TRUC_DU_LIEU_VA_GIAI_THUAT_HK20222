#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a[100], ok, cnt = 1; cin >> n; 
	for(int i = 0;i < n; i++) a[i] = i + 1;
	cout << cnt++ << ": ";
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	while(next_permutation(a, a + n)){
		cout << cnt++ << ": ";
		for(int i = 0;i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
}
