#include<bits/stdc++.h>
using namespace std;

int n, ok, a[100];

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 2) i--;
    if(i == 0) ok = 0;
    else{
        a[i]++;
        for(int j = i + 1; j <= n; j++) a[j] = 0;
    }
}

int main(){
    cin >> n; ok = 1;
    for(int i = 1; i <= n; i++) a[i] = 0;
    int cnt = 1;
    while(ok){
        if(cnt % 2 == 0){
            cout << cnt << ": ";
            for(int i = 1; i <= n; i++) cout << a[i];
            cout << endl;
        }
        cnt++;
        sinh();
    }
}
