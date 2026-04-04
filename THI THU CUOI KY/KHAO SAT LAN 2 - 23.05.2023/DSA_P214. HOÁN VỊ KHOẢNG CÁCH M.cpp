#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k, cnt = 1;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) a[i] = i + 1;
	while(next_permutation(a, a + n)){
        cnt++;
		if(cnt % k == 0){
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }
	}
}
