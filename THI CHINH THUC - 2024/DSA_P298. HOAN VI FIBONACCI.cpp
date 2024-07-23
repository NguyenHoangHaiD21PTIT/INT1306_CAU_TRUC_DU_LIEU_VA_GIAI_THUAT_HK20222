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
	cout<<"1: ";
	for(int x: a) cout<<x<<" ";
	cout<<endl;
	while(next_permutation(a, a + n)){
		cnt++;
		if(find(f, 92, cnt)){
			cout<<cnt<<": ";
			for(int x: a) cout<<x<<" ";
			cout<<endl;
		}
	}
		
}
