#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], ok;

void sinh(){
    int i = k;
    while (i >= 1 && a[i] == n - k + i) i--;
    if (!i) ok = 0;
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}

bool check (int x){
    for (int i = 1; i <= k; i++){
        if (a[i] == x) return true;
    }
    return false;
}

int main(){
    int x; ok = 1;
    cin >> n >> k >> x;
    for (int i = 1; i <= k; i++) a[i] = i;
    while (ok){
        if (check(x)){
            for (int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
        sinh();
    }
}
