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

int main(){
    int n1; cin >> n1 >> k;
	// Bước 1: Lọc trùng nhau
    set<int> se; 
    while(n1--){
        int x; cin >> x;
        se.insert(x);
    }
	// Bước 2: Chuyển sang vector
    vector<int> v;
    v.push_back(0); 
    for(int x : se) v.push_back(x);
    // Bước 3: Sinh tổ hợp theo chỉ số
    n = se.size(); ok = 1;
    for(int i = 1; i <= k; i++) a[i] = i; 
    while(ok){
        for(int i = 1; i <= k; i++) cout << v[a[i]] << " "; 
        cout << endl; sinh();
    }
}
