#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok;

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(!i) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}

bool check(){
    int sum = 0;
    for(int i = 2; i <= k; i++) sum += a[i] - a[i - 1];
    return sum > k;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++) a[i] = i;
    ok = 1;
    while(ok){
        if(check()){
            for(int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
        sinh();
    }
}