#include<bits/stdc++.h>
using namespace std;

int n, ok, a[100];

void kt(){
    for(int i = 1;i<=n;i++) a[i] = 1;
}

void sinh(){
    int i = n;
    while(i>=1&&a[i]==3) i--;
    if(i==0) ok = 0;
    else{
        a[i]++;
        for(int j = i + 1;j<=n;j++) a[j] = 1;
    }
}

int main(){
    cin>>n;
    kt();
    ok = 1;
    int cnt = 1;
    while(ok==1){
        if(cnt%2==0){
            cout<<cnt<<": ";
            for(int i = 1;i<=n;i++) cout << a[i] - 1;
            cout<<endl;
        }
        cnt++;
        sinh();
    }
}
