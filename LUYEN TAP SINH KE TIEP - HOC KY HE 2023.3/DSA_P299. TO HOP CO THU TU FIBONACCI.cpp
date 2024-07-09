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

int n, k, a[100], ok;

void kt(){
    for(int i = 1;i<=k;i++) a[i] = i;
}

void sinh(){
    int i = k;
    while(i>=1&&a[i]==n - k + i) i--;
    if(i==0) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1;j<=k;j++) a[j] = a[j - 1] + 1;
    }
}

int main(){
	gen();
	cin>>n>>k;
    kt();
    ok = 1;
    int cnt = 1;
    while(ok==1){
        if(find(f, 91, cnt)){
            cout<<cnt<<": ";
            for(int i = 1;i<=k;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        sinh();
        cnt++;
    }
}
