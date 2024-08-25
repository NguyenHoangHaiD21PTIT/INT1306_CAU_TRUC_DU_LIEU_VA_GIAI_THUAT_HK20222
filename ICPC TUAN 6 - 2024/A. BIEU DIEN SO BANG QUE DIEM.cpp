#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int f[5005], g[5005];
// f[x]: số que diêm ít nhất để tạo thành x chỉ sử dụng phép nhân 2 số nhỏ hơn x
// g[x]: số que diêm ít nhất để tạo thành x sử dụng tổng 2 số bé hơn x (trong đó 2 số có thể dùng nhân)

void kt(){
    f[1] = 1;
    g[1] = 1;
    for (int i = 2; i <= 5005; i++) {
        g[i] = i;
        for (int j = 1; j < i; j++) {
            if (i % j == 0)  g[i] = min(g[i], g[j] + 2 + g[i / j]);
        }
    }
    for (int i = 2; i <= 5005; i++) {
        f[i] = g[i];
        for (int j = 1; j < i; j++) f[i] = min(f[i], f[j] + 2 + f[i - j]);
    }
}
int main() {
    int t;
    cin >> t;
    kt();
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}

