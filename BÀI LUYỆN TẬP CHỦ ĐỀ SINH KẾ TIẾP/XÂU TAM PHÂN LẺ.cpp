#include<bits/stdc++.h>
using namespace std;

int n, ok;
char a[100];

void kt(){
    for(int i = 1; i <= n; i++) a[i] = 'A';
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 'C') i--;
    if(i == 0) ok = 0;
    else{
        a[i]++;
        for(int j = i + 1; j <= n; j++) a[j] = 'A';
    }
}

int main(){
    cin >> n; kt(); ok = 1;
    int cnt = 1;
    while(ok){
        if(cnt % 2){
            cout << cnt << ": ";
            for(int i = 1; i <= n; i++) cout << a[i];
            cout << endl;
        }
        cnt++;
        sinh();
    }
}

