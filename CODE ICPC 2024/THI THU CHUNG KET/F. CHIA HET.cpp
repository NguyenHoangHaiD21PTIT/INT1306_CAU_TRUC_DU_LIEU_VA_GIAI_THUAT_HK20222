#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin >> n;
    int a[n + 5];
    for(int i = 0; i < n; i++) cin >> a[i];
    int i = 0; // Bắt đầu từ phần tử đầu tiên
    while(i < n) {
        bool found = false;
        for(int j = i + 1; j < n; j++) {
            if(a[j] % a[i] == 0) {
                cout << a[j] << endl;
                i = j + 1; 
                found = true;
                break;
            }
        }
        if(!found) break; 
    }
}
