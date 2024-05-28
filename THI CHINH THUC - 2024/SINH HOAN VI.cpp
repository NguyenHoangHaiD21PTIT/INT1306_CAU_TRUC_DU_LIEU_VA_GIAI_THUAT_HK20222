#include<bits/stdc++.h>
using namespace std;
long long f[95];
void gen(){
	f[0] = f[1] = 1;
	for(int i = 2;i<=91;i++) f[i] = f[i - 1] + f[i - 2];
}

bool find(long long f[], int n, long long x) {
    for(int i = 0; i < n; i++) {
        if(f[i] == x) return true;
    }
    return false;
}

int main(){
	gen();
	int cnt = 1, n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++) a[i] = i + 1;
	for(int x: a) cout<<x<<" ";
	cout<<endl;
	while(next_permutation(a, a + n)){
		cnt++;
		if(find(f, 92, cnt)){
			for(int x: a) cout<<x<<" ";
			cout<<endl;
		}
	}
		
}
// 1: 1 2 3 4 
// 2: 1 2 4 3 
// 3: 1 3 2 4 
// 5: 1 4 2 3 
// 8: 2 1 4 3 
// 13: 3 1 2 4 
// 21: 4 2 1 3