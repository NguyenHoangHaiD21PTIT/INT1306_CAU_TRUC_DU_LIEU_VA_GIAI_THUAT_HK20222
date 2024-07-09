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

int n, a[100], ok;

void kt(){
    for(int i = 0;i<n;i++) a[i] = 0;
}

void sinh(){
    int i = n-1;
    while(i>=0&&a[i]==1){
        a[i] = 0;
        i--;
    }
    if(i==-1) ok = 0;
    else a[i] = 1;
}

int main(){
    gen();
    cin>>n;
    kt();
    ok = 1;
    int cnt = 1;
    while(ok==1){
        if(find(f, 92, cnt)){
            cout<<cnt<<": ";
            for(int i = 0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        cnt++;
        sinh();
    }
}
