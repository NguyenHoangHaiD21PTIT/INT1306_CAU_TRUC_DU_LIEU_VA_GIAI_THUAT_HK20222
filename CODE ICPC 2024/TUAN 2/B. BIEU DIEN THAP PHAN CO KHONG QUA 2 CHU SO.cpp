#include <bits/stdc++.h>
using namespace std;

string s;
int k, a[100], ok; // a[i] = 0 là tại đó, ta lấy con số x1, a[i] = 1 là con số x2

void kt() {
    for(int i = 0; i < k; i++) a[i] = 0;
}

void sinh() {
    int i = k - 1;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == -1) ok = 0;
    else a[i] = 1;
}

int main() {
    cin >> s;
    int n = stoi(s);
    set<int> res;
    for(int x1 = 0; x1 <= 9; x1++) {
        for(int x2 = 0; x2 <= 9; x2++){
            for(k = 1;k<=s.size();k++){ //Sinh nhị phân (x1, x2) độ dài cấu hình tăng dần từ 1 đến k
                long long num = 0;
                kt();
                ok = 1;
                for(int i = 0;i<k;i++) num = num * 10 + x1;
                while(ok) {
                    num = 0; 
                    for(int i = 0; i < k; i++) {
                        if(a[i] == 0) num = num * 10 + x1;
                        else num = num * 10 + x2;
                    }
                    if(num >= 1 && num <= n) res.insert(num);
                    sinh();
                }
            }
        }
    }
    cout << res.size() << endl;
}
