#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n, q;
	cin >> n >> q;
	vector <int> a(n + 1), kq(n + 1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] >= 0){
			kq[i] = a[i] + kq[i - 1]; 
		}
		else kq[i] = kq[i - 1];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << kq[r] - kq[l - 1] << endl;
	}
    return 0;
}
