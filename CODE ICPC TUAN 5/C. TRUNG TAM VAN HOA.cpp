#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[105];
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)  cin >> a[i];
    double p, ans = 0;
    if (k == 1) { //Trung vị
        sort(a + 1, a + n + 1);
        if(n % 2 == 1) p = a[n / 2 + 1]; 
        else p = (a[n / 2] + a[n / 2 + 1]) / 2.0; 
        for (int i = 1; i <= n; i++) ans += abs(a[i] - p);
    } else {//Trung bình
        double sum  = accumulate(a + 1, a + n + 1, 0.0);
        p = sum / n; 
        for (int i = 1; i <= n; i++) ans += (a[i] - p) * (a[i] - p);
    }
    cout << fixed << setprecision(2) << ans;
}
/*
Giả sử y = (x - a)^2 + (x - b)^2 + (x - c)^2 đạt min
y' = 2(x - a) + 2(x - b) + 2(x - c) = 2(3*x - (a + b + c)). y' có nghiệm đơn và đổi dấu qua nghiệm đơn --> y'=0 khi 3*x = (a + b + c)
*/
